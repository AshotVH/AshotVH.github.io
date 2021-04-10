const mix = require('laravel-mix');

/*
 |--------------------------------------------------------------------------
 | Mix Asset Management
 |--------------------------------------------------------------------------
 |
 | Mix provides a clean, fluent API for defining some Webpack build steps
 | for your Laravel application. By default, we are compiling the Sass
 | file for the application as well as bundling up all the JS files.
 |
 */

mix.babel('resources/js/*.js', 'public/assets/js/app.js');
mix.copyDirectory('resources/js/lib', 'public/assets/js');
mix.copyDirectory('resources/sass/lib', 'public/assets/css');
mix.copyDirectory('resources/images','public/assets/images');
mix.copyDirectory('resources/fonts','public/assets/fonts');
mix.sass('resources/sass/style.scss', 'public/assets/css/style.css').options({ processCssUrls: false });


