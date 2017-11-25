"use strict";

function IsDecimalNumber(value) {

    value = value.trim();
    if (value[0] == "+") {
        return false;
    }
    var n;
    value[0] == "-" ? n = 1 : n = 0;
    if (value.length > 1 && value[n] == "0" && value[n + 1] != ".") {
        return false;
    }
    return !isNaN(parseFloat(value)) && isFinite(value);
}

function IsPositiveInt(str) {
    if (str == null || str.length == 0) {
        return false;
    }

    str = str.trim();
    if (!(str.charCodeAt(0) >= 49 && str.charCodeAt(0) <= 57)) {
        return false;
    }
    for (var i = 1; i < str.length; i++) {
        if (!(str.charCodeAt(i) >= 48 && str.charCodeAt(i) <= 57)) {
            return false;
        }
    }
    return true;
}

function Capitalize(str) {

    if (str === null || str === "") {
        return null;
    }
    var s = str.length;
    var result = "";
    result += str[0].toUpperCase();
    for (var i = 1; i < s; i++) {
        if (str.charCodeAt(i) !== 32 && str.charCodeAt(i - 1) === 32) {
            result += str[i].toUpperCase();
        } else {
            result += str[i];
        }
    }
    return result;
}

function ExtractFirstInt(str) {
    if (str === null || str.length === 0) {
        return null;
    }
    var result = "";
    for (var i = 0, s = str.length; i < s; i++) {
        if (str.charCodeAt(i) >= 48 && str.charCodeAt(i) <= 57) {
            result += str[i];
        } else if (str.charCodeAt(i) === 45 && str.charCodeAt(i + 1) >= 48 && str.charCodeAt(i + 1) <= 57) {
            result += str[i];
        }
        else if (result.length > 0) {
            break;
        }
    }
    return Number(result);
}