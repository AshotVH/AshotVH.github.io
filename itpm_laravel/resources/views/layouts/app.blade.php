<!doctype html>
<html lang="en">
<head>
     <!-- Global site tag (gtag.js) - Google Analytics -->
     <script async src="https://www.googletagmanager.com/gtag/js?id=UA-167130958-1"></script>
     <script>
       window.dataLayer = window.dataLayer || [];
       function gtag(){dataLayer.push(arguments);}
       gtag('js', new Date());
       gtag('config', 'UA-167130958-1');
    </script>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="shortcut icon" href="{{asset('assets/images/favicon.ico')}}" type="image/x-icon">
    <link rel="stylesheet" href="{{asset('assets/css/bootstrap.min.css')}}">
    <link rel="stylesheet" href="{{asset('assets/css/style.css')}}">
    <title>Institute for Theoretical Physics and Modeling</title>
</head>
<body>
<header class="header">
    <nav class="top-menu">
        <div class="nav-bar">
            <a href="{{url('/')}}" class="nav-bar__logo">
                <img src="{{asset('assets/images/ITPM_logo.png')}}" alt="logo">
            </a>
            <div class="nav-bar__links nav-bar__links_mobile">
                <a href="{{url('/research')}}" class="nav-bar__link nav-bar__link_mobile">Research</a>
                <a href="{{url('events')}}" class="nav-bar__link nav-bar__link_mobile">Events</a>
                <a href="{{url('/news')}}" class="nav-bar__link nav-bar__link_mobile">News</a>
                <a href="{{url('/about')}}" class="nav-bar__link nav-bar__link_mobile">About</a>
            </div>
            <div class="nav-bar__mobile-button">
                <img class="nav-bar__mobile-open-menu" src="{{asset('assets/images/menu_bars.png')}}" alt="menu">
                <img class="nav-bar__mobile-close-menu" src="{{asset('assets/images/menu_exit.png')}}" alt="exit">
            </div>
        </div>
    </nav>
</header>
<main>
    <div id="home" class="home">
        <div class="home-content">
            <div class="container">
                <div class="row justify-content-start">
                    <div class="col-12 col-lg-auto">
                        <h1 class="home-content__text">Institute for Theoretical Physics and Modeling</h1>
                    </div>
                </div>
                <div class="row justify-content-end">
                    <div class="col-12 col-lg-auto">
                        <h1 class="home-content__text">Տեսական Ֆիզիկայի և Մոդելավորման Ինստիտուտ</h1>
                    </div>
                </div>
            </div>
        </div>
    </div>
    @yield('content')
</main>
<footer class="footer">
    <div class="container">
        <div class="row justify-content-between">
            <div class="col-auto">
                <h2 class="footer__h2">Institute for Theoretical Physics and Modeling</h2>
            </div>
            <div class="col-auto">
                <address>
                    <a class="footer__mail" href="mailto:info@itpm.am">info@itpm.am</a>
                </address>
            </div>
        </div>
    </div>
</footer>
<script src="{{asset('assets/js/jquery-3.2.1.min.js')}}"></script>
<script src="{{asset('assets/js/bootstrap.bundle.min.js')}}"></script>
<script src="{{asset('assets/js/app.js')}}"></script>
</body>
</html>
