#ifndef TEMPLATE_H_
#define TEMPLATE_H_

#include "../../Data/LinkedList.hpp"
#include "../../Data/CharString.h"

// Templates are HTML files where certain places can be replaced with active content.
// A good example is an entire website layout in an HTML file, where the content and
//	nav-bar are actively changed when a user goes through the website.

// Helps with the MVC model.

// Example:
// <html>
// 	<head>
// 		<link ref="css/main.css" />
// 		<script type="javascript" src="js/main.js"></script>
//		<title>{title_text}</title>
// 	</head>
//	<body>
//		<table>
//			<tr>
//				<td>{title_text}</td>
//			</tr>
//			<tr>
//				<td>{body_html}</td>
//			</tr>
//			<tr>
//				{copyright*|Eternialogic}	// <-- © EterniaLogic 2016
//				{copyright*|{url*|http://eternialogic.com|EterniaLogic}}	// <-- © <a href="http://eternialogic.com">EterniaLogic</a> 2016
//			</tr>
//		</table>
//	</body>
// </html>

// Normal types: (Replaced directly)
// {typeName}	// Direct 		{body_html}  = <h1>hah!</h1>
// {typeName&}  // HTML escapes	{body_html&} = &lt;h1&gt;hah!&lt;/h1&gt;


// Effective special types: (Asterisk used here only)
// {date*} - outputs the date in MM/DD/YYYY format
// {unixdate*} - outputs the date in seconds since 1/1/1970
// {time24*} - outputs the time in HH:MM:SS format (24 hours)
// {time12*} - outputs the time in HH:MM:SS format (12 hours)
// {url*|http://example.com|Example} - outputs a url


/*
    #include <Eternia/Encoding/HtmlEncode.h>
    #include <Eternia/WebFramework/Templates/Template.h>
    Template* t = new Template("/var/www/templates/test.htm");
    t->addDefaultDefinitions();
    CharString str("{body}");
    CharSTring* rep = new CharString("Hello! This is the body of the page!");
    t->addReplacingDefinition(str, rep);


    // Changing the replacement variable later on
    rep->set("This replaced the body of the page!");

    // Renders the new page as a string
    CharString* strout = t->render();
*/


class TemplateDefinition;


// Templates
class Template{
    LinkedList<TemplateDefinition> templateList;
public:
    Template(CharString fileloc); // pre-loads a template file

    // the replace is a pointer string, so it can be changed later with replacer->set("");
    void addRegexDefinition(CharString toreplace, CharString* replacer); // Add a regex definition, occurs every single time during a render
    void addReplacingDefinition(CharString toreplace, CharString* replacer); // Add a replacing definition, occurs every single time during a render

    void addDefaultDefinitions(); // must be called to have default definitions like {date}, {page}

    CharString render(); // Finalizes the template for usage
};


// A template definition
class TemplateDefinition{
    CharString toreplace;
    CharString* replacer;
    bool regex; // is regex or not?
public:


};

#endif

