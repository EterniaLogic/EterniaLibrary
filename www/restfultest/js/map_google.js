var testdata = {
  chicago: {
    center: {lat: 41.878, lng: -87.629},
    videos: 10
  },
  newyork: {
    center: {lat: 40.714, lng: -74.005},
    videos: 6
  },
  losangeles: {
    center: {lat: 34.052, lng: -118.243},
    videos: 5
  },
  vancouver: {
    center: {lat: 49.25, lng: -123.1},
    videos: 3
  }
};

var circles = [];
var clickedMarker = null;
var openAddVideoWindow = null;

// https://www.googleapis.com/geolocation/v1/geolocate?key=AIzaSyBfWv17NUC9P1_X_llU93cmjdpyZz2hqgI

var map;
/*function initMap() {
	map = new google.maps.Map(document.getElementById('map'), {
	  center: {lat: -34.397, lng: 150.644},
	  zoom: 5,
	  mapTypeControl: true,
		mapTypeControlOptions: {
			style: google.maps.MapTypeControlStyle.HORIZONTAL_BAR,
			position: google.maps.ControlPosition.BOTTOM_LEFT
		},
		styles: [{
			  featureType: 'poi',
			  stylers: [{ visibility: 'off' }]  // Turn off points of interest.
			}, {
			  featureType: 'transit.station',
			  stylers: [{ visibility: 'off' }]  // Turn off bus stations, train stations, etc.
			}],
		disableDoubleClickZoom: true
	});
	
	map.addListener('click', function(e) {
		// e.latLng.lat();
		// e.latLng.lng();

		// Add marker for the clicked location.
		if(clickedMarker != null){
		  // move marker
		  removeMarker(clickedMarker);
		}
	  
		 // Add a new one
		var shape = {
			coords: [1, 1, 1, 10, 14, 10, 14, 1],
			type: 'poly'
		};
			
		clickedMarker = new google.maps.Marker({
			position: {lat: e.latLng.lat(), lng: e.latLng.lng()},
			map: map,
			icon: "img/addsmall.png",
			title: "Add new Video",
			zIndex: 1
		});
		
		clickedMarker.addListener('click', addVideoButton);
	});
	
	var i=0;
	for (var city in testdata) {
		// Add the circle for this city to the map.
		var tcircle = new google.maps.Circle({
		  strokeColor: '#004de6',
		  strokeOpacity: 0.8,
		  strokeWeight: 2,
		  fillColor: '#6699ff',
		  fillOpacity: 0.65,
		  map: map,
		  center: testdata[city].center,
		  radius: Math.sqrt(testdata[city].videos*1000) * 1000
		});
		
		circles[i] = tcircle;
		i++;
		
		tcircle.addListener('click', function(e) {
			console.log(e);
	    });
    }
}*/



function initMap() {
    map = new google.maps.Map(document.getElementById('map'), {
        center: {lat: 0, lng: 0},
        zoom: 1,
        streetViewControl: false,
        mapTypeControlOptions: {
        mapTypeIds: ['moon']
        }
    });

    var moonMapType = new google.maps.ImageMapType({
        getTileUrl: function(coord, zoom) {
            var normalizedCoord = getNormalizedCoord(coord, zoom);
            if (!normalizedCoord) {
            return null;
            }
            var bound = Math.pow(2, zoom);
            return '//mw1.google.com/mw-planetary/lunar/lunarmaps_v1/clem_bw' +
                '/' + zoom + '/' + normalizedCoord.x + '/' +
                (bound - normalizedCoord.y - 1) + '.jpg';
        },
        tileSize: new google.maps.Size(256, 256),
        maxZoom: 9,
        minZoom: 0,
        radius: 1738000,
        name: 'Moon'
    });

    map.mapTypes.set('moon', moonMapType);
    map.setMapTypeId('moon');
}

// Normalizes the coords that tiles repeat across the x axis (horizontally)
// like the standard Google map tiles.
function getNormalizedCoord(coord, zoom) {
    var y = coord.y;
    var x = coord.x;

    // tile range in one direction range is dependent on zoom level
    // 0 = 1 tile, 1 = 2 tiles, 2 = 4 tiles, 3 = 8 tiles, etc
    var tileRange = 1 << zoom;

    // don't repeat across y-axis (vertically)
    if (y < 0 || y >= tileRange) {
        return null;
    }

    // repeat across x-axis
    if (x < 0 || x >= tileRange) {
        x = (x % tileRange + tileRange) % tileRange;
    }

    return {x: x, y: y};
}

function removeMarker(marker){
	marker.setMap(null);
}

// get map for other scripts
function getMap(){
	return map;
}

function addVideoButton(event){
	var lat = clickedMarker.position.lat();
	var lng = clickedMarker.position.lng();
	
	removeMarker(clickedMarker);
	
	if(openAddVideoWindow != null){
		if(openAddVideoWindow[0].parentNode == null){
			openAddVideoWindow = null;
		}
	}
	
	if(openAddVideoWindow == null){
		openAddVideoWindow = DrawAddVideoWindow(lat,lng);
	}
	
	//console.log(lat+" "+lng);
}
