#include "FileCache.h"


// file cache stores information partially on the disk and partially on the RAM.
// The most-used items will be stored on the RAM.
// This is useful for impressively BIG data sets, but not really that fast.

// A useful example for use of this, is the tile data of an item at X,Y.
// Note: This is only useful if the player is very far from the tile... if the player is close, then it must be pre-loaded.

// TODO: Follow a class's subclass data to allow complex data saving

/*template<class T>
void flushThreadst(ulong sleeptime){
    FileCache<T>* fc;
    int i=0;
    std::chrono::microseconds ms = std::chrono::microseconds(sleeptime);
    while(true ){
         FileCache::FC_flushList.freeze();
        
        for(i=0;i< FileCache::FC_flushList.frozenlen;i++){
            fc = FileCache::FC_flushList.frozen[i];
            fc->flush();
        }
        
        std::this_thread::sleep_for(ms);
    }
}*/

// thread to flush data every set # of milliseconds
/*template<class T>
void FileCache::flushThread(long milliseconds){
    // create a thread
    std::thread(flushThreadst<T>, milliseconds);
*/


template<class T>
FileCache<T>::FileCache(){
     FileCache::FC_flushList.add(this);
}

template<class T>
FileCache<T>::~FileCache(){
     FileCache::FC_flushList.remove(this);
}




template<class T>
void FileCache<T>::flush(){
    policy.flush();
}

template<class T>
void FileCache<T>::clear(){
    flush();
    
    // copy data file to backup
    CharString c = store_file+".bak";
    //std::filesystem::copy(store_file, c); // C++17
    
    // pre-close current file
    dFile.close();
    
    int result = rename(store_file.get(), c.get());
    
    if(result == 0){
        // renamed file, reinit file.
        
        iterator=0;
        dFile.open(store_file.get(), ios::out | ios::in);
    }else{
        dFile.open(store_file.get(), ios::out | ios::in);
        cout << "FileCache could not rename file before clear!" << endl;
        return;
    }
}




/*template<class T>
class FileCache {
       
        ulong max_ram_size;
        ulong current_ram_size;
        char* store_file;
        fstream dFile;
        ulong iterator;
        
        FCPolicy<T> policy;

    public:
        // file used to store data and maxSize for the file.
        FileCache(char* storeFile, ulong maxRAMSize,  FCPolicy<T> policy) {

            this.policy = policy;
            
            // init variables
            max_ram_size = maxRAMSize; // max ram size (in bytes)
            iterator=0;
            store_file = storeFile;
            current_ram_size = 0;

            // make sure it's deleted first.
            // remove(storeFile);

            // initialize the file.
            dFile.open(storeFile, ios::out | ios::in);
        };

        ~FileCache() {
            delete [] store_file;
        };

        // return!
        T* get(long id) {
            dFile.seekg((id * sizeof(T)), ios::beg);
            dFile.seekp((id * sizeof(T)), ios::beg);

            // convert data to type.
            char* tdata = (char*)malloc(sizeof(T));
            dFile.read(tdata,sizeof(T));

            // return value
            return (T*)tdata;
        };

        // returns ID
        long add(T* data) {
            long id = iterator++;

            // add item to disk
            long ID = (id * sizeof(T));
            dFile.seekp(ID, ios::beg);
            char* tdata = (char*)data;
            dFile.write(tdata,sizeof(T));
            
            //policy.add(data);
            
            return id;
        }; // set an entry


        // manual management of data
        // force these items into the RAM.
        void preload(long ID) {
            //CharString* tt = CharString::ConvertFromLong(ID);

            if(entries->get(ID) == 0x0) return; // determine if it has been added before

            loadedIDs->add(&ID);
            entries->addL(ID, get(ID));
        }

        // remove these items from the RAM. (place them back into the file cache)
        void unload(long ID) {
            //CharString* tt = CharString::ConvertFromLong(ID);
            T* data = entries->getL(ID);
            if(data == 0x0) return; // determine that it does not exists

            loadedIDs->remove(ID); // remove from the ID list
            //entries->removeL(ID); // remove data from the HashMap
            // entries[ID]

            add(data);
        }

        void clean() {
            remove(store_file);
        }
};*/
