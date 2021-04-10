$(document).ready(function () {
    const profileCardImgCorner = $('.profile-card > .profile-card__img-corner');
    const profileCardHoverImgCorner = $('.profile-card__hover-image > .profile-card__img-corner');
    profileCardImgCorner.on('click', function () {
        $(this).siblings('.profile-card__hover-image').css('display','flex');
        $(this).find('.profile-card__img-corner-plus').hide();

    });
    profileCardHoverImgCorner.on('click', function () {
        $(this).parent().css('display','none');
        $(this).parent().siblings('.profile-card__img-corner').find('.profile-card__img-corner-plus').show();
    });

});