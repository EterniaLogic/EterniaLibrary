// Draw a login window
function DrawCompanyWindow(company){
	var width = 200;
	var height = 200;
	var windowt = drawWindow("Company - "+company,"",document.body.clientWidth/2-width,document.body.clientHeight/2-height,width,height);
	document.getElementsByTagName('body')[0].appendChild(windowt[0]);
    var r="c-"+Math.random();
	
	//console.log(windowt[0].id);
	text = '<div id="'+r+'"></div>';
	windowt[2].innerHTML = text;
    setInterval("_refCompany('"+company+"','"+r+"');",100);
}

function _refCompany(company,compdiv){
    var data = '';
    //console.log(APICompanyLoc+"/"+company);
	var xhttp = getxHttpData("GET",APICompanyLoc+"/"+company);
    //xhttp.setRequestHeader("Content-type", "application/json");
    //xhttp.send(data);
    xhttp.send();
    
    xhttp.onreadystatechange = function() {
	  if (xhttp.readyState == 4 && xhttp.status == 200) {
          //console.log(xhttp.responseText);
		  _updateCompany(company,compdiv,xhttp);
	  }
	};
}

function _updateCompany(company,compdiv,xhttp){
    var datax = xhttp.responseText;
    if(datax != null && datax != ''){
        var obj = JSON.parse(datax);
        var todiv = document.getElementById(compdiv);
        if(obj.bankrupt){
            todiv.innerHTML="bankrupt";
        }else{
            data = "Money: $"+obj.money+"<br/>";
            data += "Savings: $"+obj.savings+"<br />";
            data += "Revenue: $"+obj.revenue+"<br />";
            data += "Assets Value: $"+obj.totalassets+"<hr/>";
            data += "<table style='width:100%'><tr><td>Name</td><td>Level</td><td>Revenue</td><td>Upgradeable</td></tr>"
            for(i=0;i<obj.assets.length;i++){
                var asset = obj.assets[i];
                data += "<tr><td>"+asset.name+"</td><td>"+asset.level+"</td><td>$"+asset.revenue+"</td><td>"+(obj.canupgrade?"Yes":"No")+"</td></tr>";
            }
            
            todiv.innerHTML=data;
        }
        //console.log(obj);
    }
}
