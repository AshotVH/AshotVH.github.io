@extends('layouts.app')
@section('content')
    <div id="collaborations" class="collaborations">
        <div class="container">
            <div class="row justify-content-center">
                <h1 class="collaborations__h1">Collaborations</h1>
            </div>
            <div class="row justify-content-center">
                <div class="col-12 collaborations__card">
                    <div class="row">
                        <div class="col-3">
                            <a href="https://www.dunescience.org/" target="_blank">
                                <img class="collaborations__card-image" src="{{asset('images/dune-horiz-logo-lg.png')}}"
                                     alt="DUNO logo">
                            </a>
                        </div>
                        <div class="col-auto">
                            <h2 class="collaborations__card__h2">DUNE</h2>
                            <p class="collaborations__card__sort-desc">The Deep Underground Neutrino Experiment </p>
                        </div>
                    </div>
                    <div class="row">
                        <p class="collaborations__card__long-desc">The Deep Underground Neutrino Experiment (DUNE) is a
                            leading-edge, international experiment
                            for
                            neutrino science and proton decay studies. Discoveries over the past half-century have put
                            neutrinos, the most abundant matter particles in the universe, in the spotlight for further
                            research into several fundamental questions about the nature of matter and the evolution of
                            the
                            universe — questions that DUNE will seek to answer.</p>
                    </div>
                </div>
                <div class="col-12 collaborations__card">
                    <div class="row">
                        <div class="col-3">
                            <a href="http://juno.ihep.cas.cn/" target="_blank">
                                <img class="collaborations__card-image" src="{{asset('images/JUNO.jpg')}}" alt="JUNO logo">
                            </a>
                        </div>
                        <div class="col-auto">
                            <h2 class="collaborations__card__h2">JUNO</h2>
                            <p class="collaborations__card__sort-desc">The Jiangmen Underground Neutrino Observatory</p>
                        </div>
                    </div>
                    <div class="row">
                        <p class="collaborations__card__long-desc">
                            The Jiangmen Underground Neutrino Observatory (JUNO) is a multipurpose neutrino experiment
                            designed to determine neutrino mass hierarchy and precisely measure oscillation parametersby
                            detecting reactor neutrinos from the Yangjiang and Taishan Nuclear Power Plants, observe
                            supernova neutrinos, study the atmospheric, solar neutrinos and geo-neutrinos, and perform
                            exotic searches, with a 20-thousand-ton liquid scintillator detector of unprecedented 3%
                            energy
                            resolution (at 1 MeV) at 700-meter deep underground.
                        </p>
                    </div>
                </div>
                <div class="col-12 collaborations__card">
                    <div class="row">
                        <div class="col-3">
                            <a href="https://www.hyperk.org/" target="_blank">
                                <img class="collaborations__card-image"
                                     src="{{asset('images/HKlogo-wide-color.jpg')}}" alt="HK logo">
                            </a>
                        </div>
                        <div class="col-auto">
                            <h2 class="collaborations__card__h2">HK</h2>
                            <p class="collaborations__card__sort-desc">Hyper-Kamiokande</p>
                        </div>
                    </div>


                    <div class="row">
                        <p class="collaborations__card__long-desc">Hyper-Kamiokande (HK) is to be the next generation of
                            large-scale water Cherenkov detectors.
                            It
                            is planned to be an order of magnitude bigger than its predecessor, Super-Kamiokande (SK),
                            with
                            the optimal design consisting of two half megaton tanks equiped with ultra high sensitivity
                            photosensors. The Hyper-Kamiokande detector is both a “microscope,” used to observe
                            elementary
                            particles, and also a “telescope” for observing the Sun and supernovas, using neutrinos.</p>

                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="collaborations-middle__bg"></div>
    <div id="partners" class="partners">
        <div class="container">
            <div class="row justify-content-center">
                <div class="col-12">
                    <h1 class="partners__h1">
                        partners
                    </h1>
                </div>
                <div class="col-12">
                    <h2 class="partners__h2">local partners</h2>
                    <div class="row justify-content-center">
                        <div class="col-auto">
                            <a href="https://www.yerphi.am/" class="partners__card" target="_blank">
                                <div>
                                    <img class="partners__card__img" src="{{asset('assets/images/yerphi_logo.png')}}" alt="Yerphi logo">
                                </div>
                                <h3 class="partners__card__h3">The Yerevan Physics Institute</h3>
                            </a>
                            <a href="http://www.ipr.sci.am/" class="partners__card" target="_blank">
                                <div>
                                    <img class="partners__card__img" src="{{asset('assets/images/ipr_logo.png')}}" alt="IPR">
                                </div>
                                <h3 class="partners__card__h3">The Institute for Physical Research of National Academy
                                    of Sciences of Armenia</h3>
                            </a>
                        </div>
                    </div>
                </div>
                <div class="col-12">
                    <h2 class="partners__h2">International partners </h2>
                    <div class="row justify-content-center">
                        <div class=" col-12 col-md-6 parters-int__container">
                            <a href="https://home.cern/" class="partners__card" target="_blank">
                                <div>
                                    <img class="partners__card__img" src="{{asset('assets/images/cern-logo.png')}}" alt="CERN logo">
                                </div>
                                <h3 class="partners__card__h3">CERN</h3>
                            </a>
                            <a href="https://theory.cern/" class="partners__card" target="_blank">
                                <div>
                                    <img class="partners__card__img" src="{{asset('assets/images/cern-logo.png')}}" alt="CERN logo">
                                </div>
                                <h3 class="partners__card__h3">CERN
                                    Department of Theoretical Physics</h3>
                            </a>
                        </div>
                        <div class="col-12 col-md-6 parters-int__container">
                            <a href="https://fnal.gov/" class="partners__card" target="_blank">
                                <div>
                                    <img class="partners__card__img" src="{{asset('assets/images/fermilab_logo.png')}}" alt="FERMILAB logo">
                                </div>
                                <h3 class="partners__card__h3">Fermi National Accelerator Laboratory</h3>
                            </a>
                            <a href="https://www.mpp.mpg.de/" class="partners__card" target="_blank">
                                <div>
                                    <img class="partners__card__img" src="{{asset('assets/images/Max_Planck_logo.jpeg')}}"
                                         alt="Max Planck logo">
                                </div>
                                <h3 class="partners__card__h3">The Max Planck Institute for Physics</h3>
                            </a>
                        </div>
                        <div class="col-12 col-md-6 parters-int__container">
                            <a href="https://www.physik.uzh.ch/en.html" class="partners__card" target="_blank">
                                <div>
                                    <img class="partners__card__img" src="{{asset('assets/images/uzh_logo.jpg')}}"
                                         alt="Zurich University logo">
                                </div>
                                <h3 class="partners__card__h3">Physics Institute of the University of Zurich</h3>
                            </a>
                            <a href="https://www.ictp.it/" class="partners__card" target="_blank">
                                <div>
                                    <img class="partners__card__img" src="{{asset('assets/images/ictp_logo.png')}}"
                                         alt="ICTP logo">
                                </div>
                                <h3 class="partners__card__h3">The Abdus Salam International Centre for Theoretical
                                    Physics</h3>
                            </a>
                        </div>
                        <div class="col-12 col-md-6 parters-int__container">
                            <a href="https://theory-hamburg.desy.de/" class="partners__card" target="_blank">
                                <div>
                                    <img class="partners__card__img" src="{{asset('assets/images/desy_logo.svg')}}"
                                         alt="Desy logo">
                                </div>
                                <h3 class="partners__card__h3">The DESY theory group</h3>
                            </a>
                            <a href="https://phys.technion.ac.il/en/" class="partners__card" target="_blank">
                                <div>
                                    <img class="partners__card__img" src="{{asset('assets/images/phy-logo.png')}}"
                                         alt="Technion logo">
                                </div>
                                <h3 class="partners__card__h3">The Department of Physics at Technion</h3>
                            </a>
                        </div>
                        <div class="col-12 col-md-6 parters-int__container">
                            <a href="https://www.uv.es/" class="partners__card" target="_blank">
                                <div>
                                    <img class="partners__card__img" src="{{asset('assets/images/UV_logo.png')}}"
                                         alt="University of Valencia logo">
                                </div>
                                <h3 class="partners__card__h3">University of Valencia</h3>
                            </a>
                            <a href="https://www.fuw.edu.pl/" class="partners__card" target="_blank">
                                <div>
                                    <img class="partners__card__img" src="{{asset('assets/images/Warsaw_logo.png')}}"
                                         alt="Faculty of Physics at the University of Warsaw logo">
                                </div>
                                <h3 class="partners__card__h3">Faculty of Physics at the University of Warsaw</h3>
                            </a>
                        </div>

                    </div>
                </div>
            </div>
        </div>
    </div>
    <div class="partners-middle__bg"></div>
    <div id="useful_links" class="useful-links-section">
        <div class="container ">
            <div class="row justify-content-center useful-links__head">
                <h1 class="useful-links__h1">Useful Links</h1>
            </div>
            <div class="row justify-content-center">
                <div class="col-12 col-md-6 useful_links">
                    <h2 class="useful-links__h2">HEP Database</h2>
                    <div>
                        <a class="useful-links__a" href="https://arxiv.org/" target="_blank">ArXiV</a>
                    </div>
                    <div>
                        <a class="useful-links__a" href="https://inspirehep.net/" target="_blank">iNSPIRE hep</a>
                    </div>
                </div>
                <div class="col-12 col-md-6 useful-links">
                    <h2 class="useful-links__h2">Other useful links</h2>
                    <div>
                        <a class="useful-links__a" href="http://pdg.lbl.gov/" target="_blank">Particle Data Group</a>
                    </div>
                    <div>
                        <a class="useful-links__a" href="http://www.sns.ias.edu/~jnb/" target="_blank">John Bahcall </a>
                    </div>
                    <div>
                        <a class="useful-links__a" href="https://wwwndc.jaea.go.jp/ftpnd/sae/acl.html" target="_blank">Isotope
                            Production XS</a>
                    </div>
                    <div>
                        <a class="useful-links__a" href="https://physics.nist.gov/PhysRefData/Star/Text/intro.html"
                           target="_blank">Medium Stopping Power</a>
                    </div>
                    <div>
                        <a class="useful-links__a" href="https://www.hep.anl.gov/ndk/longbnews/" target="_blank">Maury
                            Goodman's Neutrino Newsletters</a>
                    </div>
                    <div>
                        <a class="useful-links__a" href="https://www.nndc.bnl.gov/nudat2/" target="_blank">BNL nuclear
                            structure and decay data</a>
                    </div>
                </div>
            </div>
        </div>
    </div>
@endsection
