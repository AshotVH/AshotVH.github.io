"use strict";

var slider = document.getElementById("slider");
var slides = document.getElementsByClassName("slide-content");
var arrowMoveNext = document.getElementById("slider-arrow move-next");
var arrowMoveBack = document.getElementById("slider-arrow move-back");
var sliderBottomButtons = document.getElementById("slider-bottom-buttons").children;
var numberOfSlides = slides.length;
var currentSlide = 0;
var transitionTime = 1000;
var lastClick = 0;   //Last time user has clicked on the slider arrows;
function PlaceSlides() {
    slides[0].style.transform = "translate(" + 0 + "%)";
    slides[1].style.transform = "translate(" + 100 + "%)";
    for (var i = numberOfSlides - 1, position = -100; i >= 2; i--, position -= 100) {
        slides[i].style.transform = "translate(" + position + "%)";
    }
}

function SetTransition() {
    for (var i = 0; i < numberOfSlides; i++) {
        slides[i].style.transition = "transform " + transitionTime + "ms";
    }
}

function ResetTransition() {
    for (var i = 0; i < numberOfSlides; i++) {
        slides[i].style.transition = "none";
    }
}

PlaceSlides();

for (var i = 0; i < numberOfSlides; i++) {
    sliderBottomButtons[i].addEventListener("click", SlideButtonClick);
}

function SlideButtonClick(e) {
    ResetTransition();
    for (var j = 0; j < numberOfSlides; j++) {
        if (sliderBottomButtons[j] === e.target) {
            var temp = currentSlide;
            if (j > temp) {
                for (var i = 0; i < j - temp; i++) {
                    MoveNext();
                }
            } else if (j < temp) {
                for (var k = 0; k < temp - j; k++) {
                    MoveBack();
                }
            }
            sliderBottomButtons[currentSlide].style.backgroundColor = "rgba(255,255,255,0.3";
            currentSlide = j;
            sliderBottomButtons[currentSlide].style.backgroundColor = "white";
            break;
        }
    }
}

arrowMoveNext.addEventListener("click", function () {
    var currentDate = new Date();
    var clickTime = currentDate.getTime();
    if (clickTime > lastClick + transitionTime) {
        SetTransition();
        MoveNext();
        lastClick = clickTime;
    }
});

arrowMoveBack.addEventListener("click", function () {
    var currentDate = new Date();
    var clickTime = currentDate.getTime();
    if (clickTime > lastClick + transitionTime) {
        SetTransition();
        MoveBack();
        lastClick = clickTime;
    }
});


function MoveNext() {
    var nextSlide;
    var newPosition;
    if (currentSlide + 1 < numberOfSlides) {
        nextSlide = currentSlide + 1;
    } else {
        nextSlide = 0;
    }
    for (var i = 0; i < numberOfSlides; i++) {
        if (i === (currentSlide + 2) % 4) {
            slides[i].style.visibility = "hidden";
            slides[i].style.transform = "translate(100%)";
        } else {
            slides[i].style.visibility = "visible";
            newPosition = ExtractFirstInt(slides[i].style.transform) - 100;
            slides[i].style.transform = "translate(" + newPosition + "%)";
        }
    }
    sliderBottomButtons[nextSlide].style.backgroundColor = "white";
    sliderBottomButtons[currentSlide].style.backgroundColor = "rgba(255,255,255,0.3";
    currentSlide = nextSlide;
}


function MoveBack() {
    var prevSlide;
    var newPosition;
    if (currentSlide - 1 >= 0) {
        prevSlide = currentSlide - 1;
    } else {
        prevSlide = numberOfSlides - 1;
    }
    for (var i = 0; i < numberOfSlides; i++) {
        if (i === (currentSlide + 1) % 4) {
            slides[i].style.visibility = "hidden";
            slides[i].style.transform = "translate(-200%)";
        } else {
            slides[i].style.visibility = "visible";
            newPosition = ExtractFirstInt(slides[i].style.transform) + 100;
            slides[i].style.transform = "translate(" + newPosition + "%)";
        }
    }
    sliderBottomButtons[prevSlide].style.backgroundColor = "white";
    sliderBottomButtons[currentSlide].style.backgroundColor = "rgba(255,255,255,0.3";
    currentSlide = prevSlide;
}

var timerID;
var carouselPeriod = 2700;
document.onload = function () {
    SetTransition();
    timerID = setInterval(MoveNext, carouselPeriod);
};
document.addEventListener("visibilitychange", CheckVisibility);
function CheckVisibility() {
    if (!document.hidden) {
        SetTransition();
        timerID = setInterval(MoveNext, carouselPeriod);
    } else {
        clearInterval(timerID);
    }
}

slider.addEventListener("mouseover", function () {
    clearInterval(timerID);
});
slider.addEventListener("mouseout", function () {
    SetTransition();
    timerID = setInterval(MoveNext, carouselPeriod);
});

