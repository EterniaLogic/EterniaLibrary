// Window Javascript file
// © Brent Clancy 2018
// Used to manipulate custom windows
// Author: Brent Clancy (3/1/2016)

xpos = xoff = 0;
ypos = yoff = 0;
wini = 0;
selected = null;
preselected = false;
selectedr = null;


// User moves the mouse
function mouseMoveAction(e){
	//e.preventDefault();
	//console.log(e);
	if(e.changedTouches != null){
		var touches = e.changedTouches;
		for (var i = 0; i < touches.length; i++) {
			xpos = touches[i].pageX;
			ypos = touches[i].pageY;
		}
	}else{
		xpos = e.pageX;
		ypos = e.pageY;
	}
	
	if(selected != null){
		if(preselected){
			selected.style.left = (xpos-xoff)+"px";
			selected.style.top = (ypos-yoff)+"px";
		}else{
				xoff = xpos-Number(selected.style.left.replace("px",""));
				yoff = ypos-Number(selected.style.top.replace("px",""));
				//console.log(xoff+" "+yoff);
				preselected=true;
		}
	}else if(selectedr != null){
        if(preselected){
            selectedr.style.width = (xpos-xoff-Number(selectedr.style.left.replace("px","")))+"px";
            selectedr.style.height = (ypos-yoff-Number(selectedr.style.top.replace("px","")))+"px";
            selectedr.children[1].style.height = (Number(selectedr.style.height.replace("px",""))-50)+"px";
		}else{
				xoff = xpos-Number(selectedr.style.left.replace("px",""))-Number(selectedr.style.width.replace("px",""));
				yoff = ypos-Number(selectedr.style.top.replace("px",""))-Number(selectedr.style.height.replace("px",""));
				preselected=true;
		}
    }
}

function mouseReleaseAction(e){
	selected = null;
    selectedr = null;
	preselected = false;
}

// drag an object
function dragObject(e){
	selected = e;
}

function dragObjectResize(e){
	selectedr = e;
}


// create a new floating window
function drawWindow(title,content,x,y,width,height){
	var divmain = document.createElement("div");
	var divhead = document.createElement("div");
	var divbody = document.createElement("div");
    var divdrag = document.createElement("div");
	
	divmain.id = "win"+(wini++);
	divhead.id = "winh"+(wini++);
	divbody.id = "winb"+(wini++);
    divdrag.id = "wind"+(wini++);
	
	divmain.className="FloatingWindow";
	divhead.className="WindowHeader";
	
	// Set content
	divhead.innerHTML = "<table class='WindowHeader'><tr><td>"+title+"</td><td class='WindowHeaderX' onclick='destroyWindow(\""+divmain.id+"\");'>X</td></tr></table>";
	divbody.innerHTML = content;
    divdrag.innerHTML = "<table class='WindowDrag'><tr><td style='width:100%'></td><td class='WindowDragX'>/</td></tr></table>";
	
	// Add subdivs
	divmain.appendChild(divhead);
	divmain.appendChild(divbody);
    divmain.appendChild(divdrag);
	
	// style window size
	divmain.style.left=x+"px";
	divmain.style.top=y+"px";
	divmain.style.width=width+"px";
	divmain.style.height=height+"px";
    divbody.style.width="100%";
    divbody.style.height=(height-50)+"px";
    divbody.style.overflowX = "auto";
    divbody.style.overflowY = "auto";
	
	function mousedown(){
		var yl = Number(this.style.top.replace("px",""))+30;
        var yl2 = yl-30+Number(this.style.height.replace("px",""))-30;
        var xl = Number(this.style.left.replace("px",""))+Number(this.style.width.replace("px",""))-20;
        //console.log("drag "+xl+"<"+xpos+" "+yl2+"<"+ypos);
		if(yl > ypos){
			dragObject(this);
			return false;
        }else if(yl2 < ypos && xl < xpos){
            
            dragObjectResize(this);
            return false;
		}else{
			return true;
		}
	}
	
	// Bind functions.
	divmain.onmousedown = mousedown;

	divmain.addEventListener("touchstart", mousedown, false);
	divmain.addEventListener("touchend", mouseReleaseAction, false);
	//divmain.addEventListener("touchcancel", handleCancel, false);
	divmain.addEventListener("touchleave", mouseReleaseAction, false);
	divmain.addEventListener("touchmove", mouseMoveAction, false);
	
	
	return [divmain,divhead,divbody];
}

function destroyWindow(window){
	if(window !== null){
		document.getElementById(window)
			.parentNode.removeChild(document.getElementById(window));
	}
}

document.onmouseup = mouseReleaseAction;
document.onmousemove = mouseMoveAction;
//document.ondrag = mouseMoveAction;


// Draw a login window
function DrawLoginWindow(){
	var width = 200;
	var height = 200;
	var windowt = drawWindow("Login","",document.body.clientWidth/2-width,document.body.clientHeight/2-height,width,height);
	document.getElementsByTagName('body')[0].appendChild(windowt[0]);
	
	//console.log(windowt[0].id);
	logintext = '&nbsp;Username:<br />&nbsp;&nbsp;<input type="text" onclick="this.select();" style="width:180px" id="username" /><br />&nbsp;Password:<br />&nbsp;&nbsp;<input type="password" onclick="this.select();" style="width:180px" id="password" />';
	logintext += '<br /><div style="width:100%;" align=right><input type="button" onclick="doLogin(this,\''+windowt[0].id+'\',\''+windowt[2].id+'\');" value="Login" />&nbsp;</div>';
	logintext += '<br />If you have not logged in before, click here to register!';
	windowt[2].innerHTML = logintext;
}

function doLogin(e,windowid,contentid){
	//console.log("B"+contentid);
	Login(document.getElementById("username").value,
				document.getElementById("password").value,
				windowid,contentid);
}

