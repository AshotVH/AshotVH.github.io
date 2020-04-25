'use strict';

$(document).ready(function () {
    var days = $('.home-content-calendar-days');
    var hours = $('.home-content-calendar-hours');
    var minutes = $('.home-content-calendar-minutes');
    var seconds = $('.home-content-calendar-seconds');
    var finalDate = new Date(2020, 0, 1).getTime();
    setInterval(function () {
        var secondsInterval = Math.floor((finalDate - Date.now()) / 1000);
        var daysRemaining = Math.floor(secondsInterval / 86400);
        var hoursRemaining = Math.floor((secondsInterval - daysRemaining * 86400) / 3600);
        var minutesRemaining = Math.floor((secondsInterval - (daysRemaining * 86400 + hoursRemaining * 3600)) / 60);
        var secondsRemaining = Math.floor(secondsInterval - (daysRemaining * 86400 + hoursRemaining * 3600 + minutesRemaining * 60));
        days.html(daysRemaining);
        hours.html(hoursRemaining);
        minutes.html(minutesRemaining);
        seconds.html(secondsRemaining);
    }, 1000);
});

function initMap() {
    var map = new google.maps.Map(document.getElementById('map'), {
        center: { lat: 40.730610, lng: -73.935242 },
        zoom: 8
    });
}

$(document).ready(function () {
    var topMenu = $('.top-menu');
    topMenu.after('<div class="top-menu-placeholder"></div>');
    var topMenuPlaceholder = $('.top-menu-placeholder');
    var navBarMobileOpenMenu = $('.nav-bar__mobile-open-menu');
    var navBarMobileCloseMenu = $('.nav-bar__mobile-close-menu');
    var navBarLinks = $('.nav-bar__links');
    var navBarLinkMobile = $('.nav-bar__link_mobile');
    var pageWindow = $(window);
    if (pageWindow.scrollTop() >= 5) {
        topMenuPlaceholder.addClass('top-menu-fixed-top-placeholder');
        topMenu.addClass('top-menu_fixed-top');
        navBarLinks.addClass('nav-bar__links_mobile_fixed-top');
    }
    pageWindow.on('scroll', function () {
        if ($(this).scrollTop() >= 5) {
            topMenuPlaceholder.addClass('top-menu-fixed-top-placeholder');
            topMenu.addClass('top-menu_fixed-top');
            navBarLinks.addClass('nav-bar__links_mobile_fixed-top');
        } else {
            topMenu.removeClass('top-menu_fixed-top');
            topMenuPlaceholder.removeClass('top-menu-fixed-top-placeholder');
            navBarLinks.removeClass('nav-bar__links_mobile_fixed-top');
        }
    });
    var animationDuration = 0;
    navBarLinkMobile.each(function () {
        var _this = $(this);
        animationDuration += 0.5 / navBarLinkMobile.length;
        var nextAnimatedDuration = parseFloat(_this.css('animation-duration').slice(0, -1)) + animationDuration;
        nextAnimatedDuration += 's';
        _this.css('animation-duration', nextAnimatedDuration);
        _this.on('click', function () {
            closeMenuMobile();
        });
    });

    navBarMobileOpenMenu.on('click', function () {
        $(this).toggle();
        navBarMobileCloseMenu.toggle();
        navBarLinks.addClass('nav-bar__links_mobile_opening');
        setTimeout(function () {
            navBarLinks.toggleClass('nav-bar__links_mobile_opened');
        }, 50);
        navBarLinkMobile.addClass('nav-bar__link_mobile_animated');
    });

    function closeMenuMobile() {
        navBarMobileCloseMenu.toggle();
        navBarMobileOpenMenu.toggle();
        navBarLinks.toggleClass('nav-bar__links_mobile_opened');
        setTimeout(function () {
            navBarLinks.removeClass('nav-bar__links_mobile_opening');
        }, 300);
        $('.nav-bar__link_mobile').removeClass('nav-bar__link_mobile_animated');
    }

    navBarMobileCloseMenu.on('click', function () {
        closeMenuMobile();
    });

    $('.nav-bar__link').click(function () {
        var target = $("" + this.hash + "");
        $('html, body').animate({
            scrollTop: target.offset().top
        }, 600, "swing");
        return false;
    });
});

$(document).ready(function () {
    var scheduleTabs = $('.schedule-tab');
    scheduleTabs.on('click', function () {
        scheduleTabs.removeClass('schedule-tab_active');
        $(this).addClass('schedule-tab_active');
        var clickedTab = $(this).data("num");
        $('.schedule-list').removeClass('schedule-list_active');
        $('.schedule-lists [data-num=' + clickedTab + ']').addClass('schedule-list_active');
    });
});
$(document).ready(function () {
    var profileCardImgCorner = $('.profile-card > .profile-card__img-corner');
    var profileCardHoverImgCorner = $('.profile-card__hover-image > .profile-card__img-corner');
    profileCardImgCorner.on('click', function () {
        $(this).siblings('.profile-card__hover-image').css('display', 'flex');
        $(this).find('.profile-card__img-corner-plus').hide();
    });
    profileCardHoverImgCorner.on('click', function () {
        $(this).parent().css('display', 'none');
        $(this).parent().siblings('.profile-card__img-corner').find('.profile-card__img-corner-plus').show();
    });
});