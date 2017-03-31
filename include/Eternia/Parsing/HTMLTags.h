//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef HTML_Tags_h_
#define HTML_Tags_h_

// The HTML parser takes in an HTML file and converts it to it's elements.

enum HTMLTagType {TAG_a, TAG_abbr, TAG_applet, TAG_address, TAG_article, TAG_aside, TAG_audio, TAG_b, TAG_base, TAG_basefont, TAG_bdi, TAG_bdo, TAG_big, TAG_blockquote, TAG_body, TAG_br, TAG_button, TAG_canvas, TAG_caption, TAG_center, TAG_cite, TAG_code, TAG_col, TAG_colgroup, TAG_command, TAG_datalist, TAG_dd, TAG_del, TAG_details};

// Most elements have "Style", a CSS component
class HTMLStyle {

};

// Parent for all HTML tags
class HTMLTag {

};

#endif
