// Main Javascript file
// © Brent Clancy 2018
// Author: Brent Clancy (3/1/2016)

function importScript(scriptloc){
    var imported = document.createElement('script');
    imported.async=true;
    imported.defer=true;
    imported.src = scriptloc;
    document.head.appendChild(imported);
}

importScript("js/window.js");
importScript("js/cookie.js");
importScript("js/crypt.js");
importScript("js/net.js");
importScript("js/ui.js");
importScript("js/sidebar_content.js");
importScript("js/google.js");
importScript("js/Video.js");
//importScript("http://www.webglearth.com/v2/api.js");
importScript("https://apis.google.com/js/client.js?onload=googleApiClientReady");
importScript("js/map_google.js");

importScript("js/game/game.js");


function initialize3DMap() {
    var earth = new WE.map('earth_div');
    earth.setView([46.8011, 8.2266], 2);
    WE.tileLayer('http://data.webglearth.com/natural-earth-color/{z}/{x}/{y}.jpg', {
        tileSize: 256,
        bounds: [[-85, -180], [85, 180]],
        minZoom: 0,
        maxZoom: 16,
        attribution: 'WebGLEarth example',
        tms: true
    }).addTo(earth);
}


function onLoad(){
	console.log("loaded");
    //initialize3DMap();
	
	//DrawLoginWindow();
    DrawCompanyWindow("main");
    //initMap();
	
	//document.getElementById("topmenu").onclick=toggleMenu;
	//document.getElementById("toplogo").onclick=clickLogo;
	//sidebarItem(0,document.getElementById("sb0"));
}



function clickLogo(){
	location.href="http://localhost:9997";
}

function changeView(btn){
    document.getElementById("v"+btn).disabled=true;
    for(i=0;i<5;i++){
        if(i==btn) continue;
        
        document.getElementById("v"+i).disabled=false;
    }
}




