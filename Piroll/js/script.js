"use strict";


var testimonialsTextCarousel = {
    loop: true,
    center: true,
    items: 1,
    mouseDrag: false,
    dots: true,
    dotsEach: true,
    autoplay: true,
    autoplayTimeout: 3000,
    autoplayHoverPause: true,
    autoplaySpeed: 500,
    dotsSpeed: 500
};
var testimonialsBrandsCarousel = {
    loop: true,
    // autoplay: true,
    dots: false,
    autoplayTimeout: 3000,
    autoplayHoverPause: true,
    autoplaySpeed: 1000,
    responsiveClass: true,
    responsive: {
        0: {
            items: 1
        },
        480: {
            items: 2
        },
        768: {
            items: 3
        },
        991: {
            items: 4,
            margin: 60
        },
        1200: {
            items: 5,
            margin: 125
        }
    }
};

//***************** T O P  F I X E D  M E N U *****************
var topFixedMenu;
var docSectionNames = ["#home", "#about", "#work", "#process", "#services", "#testimonials", "#contact"]; //document section names
var docSections = {}; //document sections
var fixedMenuStart; //position starting from the fixed menu should appear
var topFixedMenuActive = false; //is fixed menu active

$(document).ready(function () {
    $("#testimonials .owl-carousel").owlCarousel(testimonialsTextCarousel);
    $(".section-brands .owl-carousel").owlCarousel(testimonialsBrandsCarousel);
    topFixedMenu = $('#home nav.navbar').clone(true);
    fixedMenuStart = $("#about").offset().top;
    topFixedMenu.css({
        "padding-top": "0",
        "display": "none",
        "position": "fixed",
        "top": "0",
        "left": "0",
        "width": "100%",
        "background": "white",
        "z-index": "100"
    });
    topFixedMenu.appendTo("body");
    if (window.pageYOffset > fixedMenuStart) {
        ToggleTopFixedMenu();
    }
    window.onscroll = ToggleTopFixedMenu;

    function ToggleTopFixedMenu() {
        topFixedMenu.find('a[href*="#"]').css({"color": "black"});
        topFixedMenu.find('a[href*="' + GetActiveMenuTab() + '"]').css({"color": "#66cccc"});
        if (window.pageYOffset >= fixedMenuStart) {
            if (!topFixedMenuActive) {
                $('#home nav.navbar div.collapse.navbar-collapse').attr("id", "tempid001");
                topFixedMenu.find("div.collapse.navbar-collapse").attr("id", "bs-example-navbar-collapse-1");
                topFixedMenu.css({
                    "display": "block"
                });
                topFixedMenuActive = true;
            }
        } else {
            if (topFixedMenuActive) {
                $('#home nav.navbar div.collapse.navbar-collapse').attr("id", "bs-example-navbar-collapse-1");
                topFixedMenu.find("div.collapse.navbar-collapse").attr("id", "tempid001");
                topFixedMenu.css({
                    "display": "none"
                });
                topFixedMenuActive = false;
            }
        }
    }
});

function GetActiveMenuTab() {
    for (var i = 0; i < docSectionNames.length; i++) {
        docSections[docSectionNames[i]] = $(docSectionNames[i]).offset().top;
    }
    var activeMenuTab = docSectionNames[0];
    for (var key in docSections) {
        if (window.pageYOffset >= docSections[key] - 200) {
            activeMenuTab = key;
        } else {
            return activeMenuTab;
        }
    }
}

$('nav.navbar ul > li > a[href^="#"]').click(function () {
    var target = $("" + this.hash + "");
    $('html, body').animate({
        scrollTop: target.offset().top
    }, 600, "swing");
    return false;
});
//***************** T O P  F I X E D  M E N U  E N D *****************



