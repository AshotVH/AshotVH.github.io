$(document).ready(function () {
    const body = $('body');
    const navBarMobileOpenMenu = $('.nav-bar__mobile-open-menu');
    const navBarMobileCloseMenu = $('.nav-bar__mobile-close-menu');
    const navBarLinks = $('.nav-bar__links');
    const navBarLinkMobile = $('.nav-bar__link_mobile');
    let animationDuration = 0;
    navBarLinkMobile.each(function () {
        let _this = $(this);
        animationDuration += 0.5 / navBarLinkMobile.length;
        let nextAnimatedDuration = parseFloat(_this.css('animation-duration').slice(0, -1)) + animationDuration;
        nextAnimatedDuration += 's';
        _this.css('animation-duration', nextAnimatedDuration);
        _this.on('click', function () {
            closeMenuMobile();
        });
    });
    navBarMobileOpenMenu.on('click', function () {
        $(this).toggle();
        navBarMobileCloseMenu.toggle();
        body.css('overflow-y','hidden');
        navBarLinks.addClass('nav-bar__links_mobile_opening');
        setTimeout(function () {
            navBarLinks.toggleClass('nav-bar__links_mobile_opened');
        }, 50);
        navBarLinkMobile.addClass('nav-bar__link_mobile_animated');
    });
    function closeMenuMobile() {
        navBarMobileCloseMenu.toggle();
        navBarMobileOpenMenu.toggle();
        body.css('overflow-y','auto');
        navBarLinks.toggleClass('nav-bar__links_mobile_opened');
        setTimeout(function () {
            navBarLinks.removeClass('nav-bar__links_mobile_opening');
        }, 300);
        $('.nav-bar__link_mobile').removeClass('nav-bar__link_mobile_animated');
    }
    navBarMobileCloseMenu.on('click', function () {
        closeMenuMobile();
    });
});



