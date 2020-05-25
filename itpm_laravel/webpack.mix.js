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

mix.babel('resources/js/*.js', 'public/js/app.js');
// mix.js('resources/js/app.js','public/js');
mix.copyDirectory('resources/js/lib', 'public/js');
mix.copyDirectory('resources/sass/lib', 'public/css');
mix.copyDirectory('resources/images','public/images');
mix.copyDirectory('resources/fonts','public/fonts');
mix.sass('resources/sass/style.scss', 'public/css/style.css').options({ processCssUrls: false });


