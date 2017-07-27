$(function() {

    // smooth scroll
    var navbarTop=60;
    $('a[href*=#]:not([href=#])').click(function() {
        if (location.pathname.replace(/^\//,'') == this.pathname.replace(/^\//,'') && location.hostname == this.hostname) {
            var target = $(this.hash);
            target = target.length ? target : $('[name=' + this.hash.slice(1) +']');
            if (target.length) {
                $('html,body').animate({
                    scrollTop: target.offset().top-navbarTop
                }, 1000);
                return false;
            }
        }
    });


    $(window).scroll(function() {
        var winSize={
            "width" : window.innerWidth,
            "height" : window.innerHeight
        };
        var y = $(this).scrollTop();
        var windowH=winSize.height;
        var sysPicPos=$("#sysreqpic").offset();
        var appsPicPos=$("#appspic").offset();
        var setupPicPos=$("#setuppic").offset();
        var a01x=0.3*y-130, a01y=0.2*y-420;
        var b=appsPicPos.top-winSize.height;
        var a02x=0.15*y-260, a02y=0.1*y-100;
        var a03x=100, a03y=-0.2*y+20;
        if(y>1) {
            $("#appspic").css("background-position", "" + a02x + "px " + a02y +"px");
            $("#sysreqpic").css("background-position", "-" + a01x + "px " + a01y +"px");
            $("#setuppic").css("background-position", "-" + a03x + "px " + a03y +"px");
        }

    });
    
});

var browser, icon=false, brInfo;
var canaryVersion=35;
var userAgent = window.navigator.userAgent.toLowerCase() || "unkown";
var icons = {
        "canary" : "<img class=\"reqicon\" src=\"images/chrome_canary_icon.png\" width=\"20px\">",
        "chrome" : "<img class=\"reqicon\" src=\"images/chrome_icon.png\" width=\"20px\">",
        "mac" : "<img class=\"reqicon\" src=\"images/macos.png\" width=\"20px\">",
        "windows" : "<img class=\"reqicon\" src=\"images/windows.png\" width=\"20px\">",
        "unknown" : "<span class=\"glyphicon glyphicon-question-sign\"></span> "
};

if(userAgent.search(/chrome/)!=-1) {
    var version=parseInt(userAgent.substr(userAgent.search(/chrome/)+6+1, 2));
    var brVersion=version;
    if(version>=35) {
        icon=icons["canary"];
        brInfo="canary";
    } else {
        icon=icons["chrome"];
        brInfo="chrome";
    }
    if(typeof version!="number") {
        version="識別できませんでした";
        icon= icons["canary"] + icons["chrome"];
    }
    browser= "Chrome (Version: " + version + ")";
} else {
    browser="Chrome以外";
    brInfo="notchrome";
}
if(icon===false) {
    icon=icons["unknown"];
}
document.getElementById("userAgent").innerHTML=icon + browser;

var osInfo, iconos=false, opsysInfo;
if(userAgent.search(/windows/)!=-1) {
    osInfo="Windows";
    iconos=icons["windows"];
    opsysInfo="windows";
} else if(userAgent.search(/mac/)!=-1 && ( userAgent.search(/iphone/)==-1 && userAgent.search(/ipad/)==-1)) {
    opsysInfo="mac";
    var version=parseInt(userAgent.substr(userAgent.search(/mac os x /)+9, 4).replace(/_|\./, ""));
    if(typeof version=="number") {
        version = version/10;
    } else {
        version="識別できませんでした";
    }
    osInfo="Mac OS X (Version: " + version + ")";
    iconos=icons["mac"];
} else {
    osInfo="Mac、Windows以外";
}
if(iconos===false) {
    iconos=icons["unknown"];
}
document.getElementById("osInfo").innerHTML=iconos + osInfo;

if(brInfo=="chrome" && brVersion>=33) {
    document.getElementById("ready").innerHTML="Ready!! <span class=\"glyphicon glyphicon-wrench\"></span> セットアップへ";

    document.getElementById("chromeDlLink").style.setProperty("visibility", "hidden");
    document.getElementById("chromeDlLink").style.setProperty("display", "none");

    document.getElementById("chromeInstallInstruction").style.setProperty("visibility", "hidden");
    document.getElementById("chromeInstallInstruction").style.setProperty("display", "none");
}
