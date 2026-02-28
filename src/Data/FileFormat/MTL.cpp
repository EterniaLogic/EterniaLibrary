#include "MTL.h"

LinkedList<IMaterial*> MTL::loadFromFile(CharString mtlFile) {
    cout << "Loading Materials: " << mtlFile << endl;
    cout.flush();

    LinkedList<CharString> linet;
    // load and parse file.
    // gets ALL lines from the file.
    LinkedList<IMaterial*> materials;
    IMaterial* material = 0x0;
    int i=0;

    //this->rendermode=GL_QUADS;

    ifstream filex;
    //cout << "aa" << endl; cout.flush();
    fileOpen(filex, mtlFile.get());

    CharString readx;
    CharString hash = CharString("#");
    CharString slash = CharString("//");
    CharString brack = CharString("[");

    // Read lines from the file
    while((readx = fileGetLine(filex)).getSize() > -1) {
        //debugLogmm("Line: " << readx.get());

        // Test for line comments
        if(!readx.startsWith(hash) && !readx.startsWith(slash) && !readx.startsWith(brack)) {
            //debugLogmm("Line: " << readx.get());
            linet = readx.split(' ', '`');
            //list2
            // test if line is a valid OBJ value
            if(linet.size() > 1) {

                if(linet.get(0).compare("newmtl",6)) { // Ambient color
                    debugLogmm("newmtl " << linet.get(1));
                    material = new IMaterial();
                    material->name = linet.get(1);
                    materials.add(material);
                } else if(linet.get(0).compare("Ka",2)) { // Ambient color
                    debugLogmm("Ka " << linet.get(1).getFloat() << " " << linet.get(2).getFloat() << " " << linet.get(3).getFloat());

                    material->AmbientColor = Math::vertex(linet.get(1).getFloat(), linet.get(2).getFloat(), linet.get(3).getFloat());
                } else if(linet.get(0).compare("Kd",2)) { // Diffuse Color
                    debugLogmm("Kd " << linet.get(1).getFloat() << " " << linet.get(2).getFloat() << " " << linet.get(3).getFloat());

                    material->DiffuseColor = Math::vertex(linet.get(1).getFloat(), linet.get(2).getFloat(), linet.get(3).getFloat());
                } else if(linet.get(0).compare("Ks",2)) { // Specular Color
                    debugLogmm("Ks " << linet.get(1).getFloat() << " " << linet.get(2).getFloat() << " " << linet.get(3).getFloat());

                    material->SpecularColor = Math::vertex(linet.get(1).getFloat(), linet.get(2).getFloat(), linet.get(3).getFloat());
                } else if(linet.get(0).compare("Ke",2)) { // Emit Color
                    debugLogmm("Ke " << linet.get(1).getFloat() << " " << linet.get(2).getFloat() << " " << linet.get(3).getFloat());

                    material->EmitColor = Math::vertex(linet.get(1).getFloat(), linet.get(2).getFloat(), linet.get(3).getFloat());
                } else if(linet.get(0).compare("Ni",2)) { // Shininess
                    debugLogmm("Ni " << linet.get(1).getFloat());

                    material->Shininess = linet.get(1).getFloat();
                } else if(linet.get(0).compare("illum",5)) { // Illumination model
                    debugLogmm("illum " << linet.get(1).getFloat());

                    material->Illumination = linet.get(1).getFloat();
                } else if(linet.get(0).compare("d",1)) { // Alpha (dissolved)
                    debugLogmm("d " << linet.get(1).getFloat());

                    material->Alpha = linet.get(1).getFloat();
                } else if(linet.get(0).compare("Tr",2)) { // Alpha reversed (Opaque)
                    debugLogmm("Tr " << linet.get(1).getFloat());

                    material->Alpha = 1-linet.get(1).getFloat();
                } else if(linet.get(0).compare("map_aas",6)) { // Anti-Aliasing on/off for textures?
                    debugLogmm("map_aat " << linet.get(1));

                }


                // color maps
                else if(linet.get(0).compare("map_Ka",6)) { // Ambient color map
                    //ColorMap.openImage(*(linet.get(1)),false);
                    material->ColorMap_loc = linet.get(1);
                    debugLogmm("map_Ka " << linet.get(1));

                } else if(linet.get(0).compare("map_Kd",6)) { // Diffuse Color map
                    //DiffuseMap.openImage(*(linet.get(1)),false);
                    material->DiffuseMap_loc = linet.get(1);
                    debugLogmm("map_Kd " << linet.get(1));

                } else if(linet.get(0).compare("map_Ks",6)) { // Specular Color map
                    //SpecularMap.openImage(*(linet.get(1)),false);
                    material->SpecularMap_loc = linet.get(1);
                    debugLogmm("map_Ks " << linet.get(1));

                } else if(linet.get(0).compare("map_Ke",6)) { // Emit Color map
                    //EmitMap.openImage(*(linet.get(1)),false);
                    material->EmitMap_loc = linet.get(1);
                    debugLogmm("map_Ke " << linet.get(1));

                } else if(linet.get(0).compare("map_Ni",6)) { // Shininess map
                    //ShinyMap.openImage(*(linet.get(1)),false);
                    material->ShinyMap_loc = linet.get(1);
                    debugLogmm("map_Ni " << linet.get(1));

                }

                // geometry maps
                else if(linet.get(0).compare("bump",4) || linet.get(0).compare("map_bump",8)) { // Bump map
                    //BumpMap.openImage(*(linet.get(1)),false);
                    material->BumpMap_loc = linet.get(1);
                    debugLogmm("bump " << linet.get(1));

                } else if(linet.get(0).compare("disp",4)) { // disposition scalar map
                    debugLogmm("disp " << linet.get(1));

                } else if(linet.get(0).compare("decal",5)) { // Decal??? map (how colors are blended)
                    debugLogmm("decal " << linet.get(1));

                } else if(linet.get(0).compare("refl",4)) { // Mirror intensity map
                    //MirrorMap.openImage(*(linet.get(1)),false);
                    material->MirrorMap_loc = linet.get(1);
                    debugLogmm("refl " << linet.get(1));
                } else if(linet.get(0).compare("transparency",12)) { // Alpha intensity map
                    //AlphaMap.openImage(*(linet.get(1)),false);
                    material->AlphaMap_loc = linet.get(1);
                    debugLogmm("transparency " << linet.get(1));
                }
            }
            //delete linet;
        }
    }

    fileClose(filex);

    return materials;
}
