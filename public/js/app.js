$(document).ready(function () {
  var body = $('body');
  var navBarMobileOpenMenu = $('.nav-bar__mobile-open-menu');
  var navBarMobileCloseMenu = $('.nav-bar__mobile-close-menu');
  var navBarLinks = $('.nav-bar__links');
  var navBarLinkMobile = $('.nav-bar__link_mobile');
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
    body.css('overflow-y', 'hidden');
    navBarLinks.addClass('nav-bar__links_mobile_opening');
    setTimeout(function () {
      navBarLinks.toggleClass('nav-bar__links_mobile_opened');
    }, 50);
    navBarLinkMobile.addClass('nav-bar__link_mobile_animated');
  });

  function closeMenuMobile() {
    navBarMobileCloseMenu.toggle();
    navBarMobileOpenMenu.toggle();
    body.css('overflow-y', 'auto');
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
