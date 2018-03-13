"use strict";

function startSlider(slides) {
    var numberOfSlides = slides.length;
    for (var i = 0; i < numberOfSlides; i++) {
        if (slides[i].classList.contains("slider__slide_active")) {
            slides[i].classList.remove("slider__slide_active");
            if (i + 1 < numberOfSlides) {
                slides[i + 1].classList.add("slider__slide_active");
            } else {
                slides[0].classList.add("slider__slide_active");
            }
            break;
        }
    }
}

var pieChartActive = false;
$(document).ready(function () {
    var slides = document.querySelectorAll(".slider__slide");
    setInterval(function () {
        startSlider(slides);
    }, 5000);
    if ($(window).scrollTop() + $(window).height() >= $('.charts').offset().top && !pieChartActive) {
        $(function () {
            $('.chart__circle').easyPieChart({
                barColor: "#3498db",
                animate: 1200
            });
        });
        pieChartActive = true;
    }
    $('.top-menu .nav-link').click(function () {
        var target = $("" + this.hash + "");
        $('html, body').animate({
            scrollTop: target.offset().top
        }, 600, "swing");
        return false;
    });
    $(window).on('scroll', function () {
        var navbar = $('.top-menu > .navbar');
        if ($(this).scrollTop() >= $('#profile').offset().top) {
            navbar.addClass('fixed-top top-menu__navbar-fixed');
        } else {
            navbar.removeClass('fixed-top top-menu__navbar-fixed');
        }
        if ($(window).scrollTop() + $(window).height() >= $('.charts').offset().top && !pieChartActive) {
            $(function () {
                $('.chart__circle').easyPieChart({
                    barColor: "#3498db",
                    animate: 1200
                });
            });
            pieChartActive = true;
        }
    });

    $('body').scrollspy({target: '.top-menu'});
    $('#portfolio .nav .nav-link').on('click', function () {
        $('#portfolio .nav .nav-link.active').removeClass('active');
        $(this).addClass('active');
        return false;
    });
    var $lightGallery = $("#lightgallery");
    $lightGallery.lightGallery({
        thumbnail: true
    });
    var $grid = $('.grid').isotope({
        itemSelector: '.grid-item',
        layoutMode: 'fitRows',
        transitionDuration: 500
    });

    $('[data-grid-btn]').on('click', function (event) {
        var filterValue = $(this).attr('data-grid-btn');
        if (filterValue === 'all') {
            filterValue = '*';
        } else {
            filterValue = '[data-grid-item-info=' + filterValue + ']';
        }
        $grid.isotope({filter: filterValue});
        $lightGallery.data('lightGallery').destroy(true);
        if (filterValue === '*') {
            $lightGallery.lightGallery({
                thumbnail: true
            });
        } else {
            $lightGallery.lightGallery({
                thumbnail: true,
                selector: filterValue
            });
        }
    });
});