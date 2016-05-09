#ifndef JSON_H_
#define JSON_H_

// JSON is a language that helps make text human readable between the server and client.

class JSON{
private:
	CharString* data;
public:
	JSON(CharString* data);
	
	void loadFile(CharString* loc); // load JSON from file
	void saveFile(CharString* loc); // save JSON (overwrite) to file
	
	// Static methods to help speed up the process
	CharString* static encode(CharString* data);
	CharString* static decode(CharString* data);
};


#endif