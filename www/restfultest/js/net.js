// Networking Javascript file
// © Brent Clancy 2018
// Used to connect with the API
// Author: Brent Clancy (3/1/2016)

// Unoptimized v0.1

// List of API server locations
//var APILoc = "http://eternialogic.com:630";
var APILoc = "..";

var APIP = APILoc+"/api";
var APICompanyLoc = APIP+"/company";
var APIAuthLoc = APIP+"/login";

Token = "";
UUID = "";

function Getxhttp(){
	var xhttp;
	if (window.XMLHttpRequest) {
		xhttp = new XMLHttpRequest();
		} else {
		// code for IE6, IE5
		xhttp = new ActiveXObject("Microsoft.XMLHTTP");
	}
	return xhttp;	
}

function getxHttpData(method,url){
	var xhttp = Getxhttp();
	
	xhttp.open(method, url, true);
	
	return xhttp;
}

// since the hash will be semi-public, best to prevent man-in-the-middle attacks.
function Login(username,password,contentdiv,responsediv){ 
    var passhash = SHA256("ewal?"+password+"ifnk"+hex_md5(password+"pwqojaso;lfm;flsmg;l1ml;m;lmhaoshlgk"));
	var data = '{"username":"'+username+'","password":"'+passhash+'"}';
	var xhttp = getxHttpData("POST",APIAuthLoc);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send(data);
	
	xhttp.onreadystatechange = function() {
	  if (xhttp.readyState == 4 && xhttp.status == 200) {
		onLogin(contentdiv,responsediv,xhttp.responseText);
	  }
	};
}

function onLogin(contentdiv,responsediv,response){
	//console.log(responsediv);
    console.log(response);
	document.getElementById(responsediv).innerHTML = response;
	
	// parse and use json
	var obj = JSON.parse(response);
	if(obj !== null){
		if(obj.Type !== null){
			if(obj.Type == "Authentication") {
				Token = obj.Token;
				UUID = obj.ID;
				destroyWindow(contentdiv);
				
				SetCookie(_cookieNames[0],Token);
				SetCookie(_cookieNames[1],UUID);
			}
		}
	}
}


