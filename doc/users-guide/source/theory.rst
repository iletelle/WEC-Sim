
.. _theory:

Theory
======
Introduction
--------------
Modeling a WEC involves the interaction between the incident waves, device motion, PTO mechanism, and mooring (:ref:`wec_sim_methodology`). WEC-Sim uses a radiation and diffraction method :cite:`Li2012,Babarit2012` to predict power performance and design optimization. The radiation and diffraction method generally obtains the hydrodynamic forces from a frequency-domain boundary element method (BEM) solver using linear coefficients to solve the system dynamics in the time domain.

.. _wec_sim_methodology:

.. figure:: _static/Physics.png
	
   WEC-Sim methodology


Boundary Element Method
----------------------------------
A common approach to determining the hydrodynamic forces is to presume that they are the sum of incident, radiated, and diffracted wave components. These forcing components are modeled using linear coefficients ideally obtained from a frequency-domain potential flow BEM solver (e.g., WAMIT :cite:`Lee2006`, AWQA-FER :cite:`AQWA`, and Nemoh :cite:`NEMOH`). The BEM solutions are obtained by solving the Laplace equation for the velocity potential, which assumes the flow is inviscid, incompressible, and irrotational. More details on the theory for the frequency-domain BEM can be found in :cite:`Lee2006`.

Coordinate System in WEC-Sim
------------------------------
The :ref:`coordinate_system` figure illustrates a 3-D floating point absorber subject to incoming waves in water. The figure also defines the coordinates and the 6 DOF in WEC-Sim. The WEC-Sim coordinate system  assumes that the  X axis is in the direction of wave propagation if the wave heading angle is equal to zero. The Z axis is in the vertical upwards direction, and the Y axis direction is defined by the right-hand rule. In the vectors and matrices used in the code, surge (x), sway (y), and heave (z) correspond to the first, second and third position respectively. Roll (Rx), Pitch (Ry), and Yaw (Rz) correspond to the fourth, fifth, and sixth position respectively.

.. _coordinate_system:

.. figure:: _static/coordinateSystem.png

   WEC-Sim coordinate system


Time-Domain Numerical Method
------------------------------------
The dynamic response of the system was calculated by solving the equation of motion for WEC systems :cite:`Babarit2012,Nolte2014`. The equation of motion for a floating body, about its center of gravity, can be given as:

.. math::

	m\ddot{X}=F_{ext}+F_{rad}+F_{PTO}+F_{v}+F_{B}+F_{m},


where :math:`\ddot{X}` is the (translational and rotational) acceleration vector of the device, :math:`m` is the mass matrix, :math:`F_{ext}` is the wave excitation force vector, :math:`F_{rad}` is the force vector resulting from wave radiation, :math:`F_{PTO}` is the PTO force vector, :math:`F_{v}` is the damping force vector, :math:`F_{B}` is the net buoyancy restoring force vector, and :math:`F_{m}` is the force vector resulting from the mooring connection.

Both :math:`F_{ext}` and :math:`F_{rad}` are calculated from values provided by the frequency-domain BEM solver. The radiation term includes an added-mass and wave damping term associated with the acceleration and velocity of the floating body, respectively. The wave excitation term includes a Froude-Krylov force component generated by the undisturbed incident waves and a diffraction component that results from the presence of the floating body. WEC-Sim can be used for regular and irregular wave simulations, but note that :math:`F_{ext}` and :math:`F_{rad}` are calculated differently for sinusoidal steady-state response scenarios and random sea simulations. The sinusoidal steady-state response is often used for simple WEC designs with regular incoming waves. However, for random sea simulations or any simulations where fluid memory effects of the system are essential, the convolution integral method is recommended to represent the fluid memory retardation force on the floating body.

Sinusoidal Steady-State Response Scenario
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
This approach assumes that the system response is in sinusoidal steady-state form, and is only valid for regular wave simulations. The radiation term can be calculated using the added mass and the wave radiation damping term for a given wave frequency, which is obtained .. from

.. math::

	F_{rad}=-A(\omega_{r})\ddot{X}-B(\omega_{r})\dot{X},

where :math:`A(\omega_{r})` and :math:`B(\omega_{r})` are the added-mass and wave radiation damping matrices, respectively. :math:`\omega_{r}` is the wave frequency (in rad/sec), and :math:`\dot{X}` is the velocity vector of the floating body.

The free surface profile is based on linear wave theory for a given wave height, wave frequency, and water depth. The regular wave excitation force is obtained from

.. math::

	F_{ext}=\Re\left[ R_{f}\frac{H}{2}F_{X}(\omega_{r})e^{i(\omega_{r}t)} \right],\label{eq:RegularWaveExt}


where :math:`\Re` denotes the real part of the formula, :math:`R_{f}` is the ramp function, :math:`H` is the wave height, and :math:`F_{X}` is the excitation vector, including the magnitude and phase of the force.

Convolution Integral Formulation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
To include the fluid memory effect on the system, the convolution integral calculation, which is based upon the Cummins equation :cite:`Cummins1962`, is used The radiation term can be calculated by

.. math::

	F_{rad}=-A_{\infty}\ddot{X}-\intop_{0}^{t}K(t-\tau)\dot{X}(\tau)d\tau,

where :math:`A_{\infty}` is the added mass matrix at infinite frequency and :math:`K` is the impulse response function.

For regular waves, the equation discribed in the last subsection is used to calculate the wave excitation force. For irregular waves, the free surface elevation is constructed from a linear superposition of a number of regular wave components. It is often characterized using a wave spectrum (Figure \ref{fig:An-example-of PM Spectrum}) that describes the wave energy distribution over a range of wave frequencies, characterized by a significant wave height and peak wave period. The irregular excitation force can be calculated as the real part of an integral term across all wave frequencies as follows 

.. math::

	F_{ext}=\Re\left[ R_{f} F_{X}(\omega_{r})e^{i(\omega_{r}t+\phi)} \intop_{0}^{\infty}\sqrt{2S(\omega_{r})d\omega_{r}} \right],

where :math:`S` is the wave spectrum and :math:`\phi` is a random phase angle. 

.. figure:: _static/WaveElevation.png

   An example of wave spectrum and irregular wave elevation generated by WEC-Sim (Pierson\textendash Moskowitz spectrum)\label{fig:An-example-of PM Spectrum

State Space Representation of :math:`K_{r}`
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
It is highly desirable to represent the radiation convolution integral discribed in the last subsection in state space (SS) form :cite:`Yu1996`.  This has been shown to dramatically increase computational speeds :cite:`Taghipour2008` and allow for conventional control methods, that rely on linear state space models, to be used.  An approximation will need to be made as :math:`K_{r}` is solved from a set of partial differential equations where as a linear state space is constructed from a set of ordinary differential equations.  In general it is desired to make the following approximation:

.. math::

	\mathbf{\dot{X}_{r}} \left( t \right) = \mathbf{A_{r}} \mathbf{X_{r}} \left( t \right) + \mathbf{B_{r}} \mathbf{\dot{\zeta}} (t);~~\mathbf{X_{r} }\left( 0 \right) = 0~~, \nonumber \\
	\int_{-\infty}^{t} \mathbf{K_{r}} \left( t- \tau \right) d\tau \approx \mathbf{C_{r}} \mathbf{X_{r}} \left( t \right) + \mathbf{D_{r}} \mathbf{\dot{\zeta}} \left( t \right)~~,

with :math:`\mathbf{A_{r}},~\mathbf{B_{r}},~\mathbf{C_{r}},~\mathbf{C_{r}},~\mathbf{D_{r}}` being the time-invariant state, input, output, and feed through matrices, while :math:`\dot{\zeta}` is the input to the system.

Calculation of :math:`K_{r}` from State Space Matrices
......................................................

The impulse response of a single-input state-space model represented by:

.. math::

	\dot{x} &=&  \mathbf{A_{r}}x + \mathbf{B_{r}} u~~,\\
	y &=& C_{r} \mathbf{x}~~,

which is the same as the unforced response, (:math:`u=0`), with the initial states set to :math:`\mathbf{B_{r}}`:

.. math::

	\dot{x} &=& \mathbf{A_{r}} x~~,~~x(0)= \mathbf{B_{r}}~~,\\
	y &=& \mathbf{C_{r}} x~~,

The impulse response of a continuous system with a nonzero :math:`D` matrix is infinite at :math:`t=0`, therefore the lower continuity value :math:`\mathbf{C_{r}}\mathbf{B_{r}}` is reported at :math:`t=0`. The general solution to a linear time invariant (LTI) system is given by:

.. math::

	x(t) = e^{\mathbf{A_{r}}t} x(0) + \int_{0}^{t} e^{\mathbf{A_{r}}(t-\tau)} \mathbf{B_{r}} u (\tau) d\tau~~,

where :math:`e^{\mathbf{A_{r}}}` is called the matrix exponential and the calculation of :math:`K_{r}` follows:

.. math::

	K_{r}(t) = \mathbf{C_{r}}e^{\mathbf{A_{r}}t}\mathbf{B_{r}}~~.

Laplace Transform and Transfer Function
......................................................
The Laplace transform is a common integral transform in mathematics.  It is a linear operator of a function that transforms :math:`f(t)` to a function :math:`F \left( s \right)` with complex argument :math:`s`, which is calculated from the integral

.. math::

	F \left( s \right) = \int_{0}^{\infty} f \left( t \right) e^{-st} dt~~,

where the derivative of :math:`f \left( t \right)` has the following laplace transform

.. math::

	sF \left( s \right) = \int_{0}^{\infty} \frac{df \left( t \right)}{dt} e^{-st} dt~~,

The Laplace transform has some useful relationships, the first relation used later in this document is the initial value theorem:

.. math::

	f \left( 0^{+} \right) = \lim_{s \rightarrow \infty} s F \left( s \right)~~,

and the final value theorem:

.. math::

	f \left( \infty \right) = \lim_{s \rightarrow 0} s F \left( s \right)~~.

Consider a linear input/output system described by the following differential equation

.. math::

	\frac{d^{m}y}{dt^{m}}+a_{1}\frac{d^{m-1}y}{dt^{m-1}}+\ldots + a_{m}y = b_{0}\frac{d^{n}u}{dt^{n}} + b_{1}\frac{d^{n}u}{dt^{n}} + \ldots + b_{n} u~~,

where :math:`y` is the output and :math:`u` the input.  After taking the Laplace Transform of equation above, the differential equation is now completely described by two polynomials

.. math::

	& A \left( s \right) = s^{m} + a_{1} s^{m-1} + \ldots + a_{m-1}s + a_{m}~~,& \\
	& B \left( s \right) = b_{0}s^{n} + b_{1}s^{n-1} + \ldots + b_{n-1}s + b_{n}~~,&

where :math:`A \left( s \right)` is characteristic polynomial of the system.  The polynomials can be inserted into Eqn.~(\ref{eqn:ODE}) leading to:

.. math::

	G \left( s \right)=\frac{Y\left( s \right)}{U \left( s \right)} = \frac{s^{m} + a_{1} s^{m-1} + \ldots + a_{m-1}s + a_{m} }{b_{0}s^{n} + b_{1}s^{n-1} + \ldots + b_{n-1}s + b_{n}}~~,

where :math:`G\left( s \right)` is the transfer function.  If the state, input, output, and feedthrough matrices are known the transfer function of the system can be calculated from:

.. math::

	G \left( s \right) = C \left( sI - A \right)^{-1}B + D~~.

The frequency response of the system can be obtained by substituting :math:`j\sigma` for :math:`s`, for the frequency range of interest, where the magnitude and phase of :math:`G \left( j\sigma \right)` can be calculated with the results commonly presented in a Bode plot.

Realization Theory
......................................................
The state space realization of the hydrodynamic radiation coefficients can be pursued in the time domain (TD). This consists of finding the minimal order of the system and the discrete time state matrices (:math:`\mathbf{A_{d}},~\mathbf{B_{d}},~\mathbf{C_{d}},~\mathbf{D_{d}}`) from a matrix assembly from the samples of the impulse response function.  This problem is easier to handle for a discrete-time system than for continuous-time, the reason being that impulse response function of a discrete-time system is given by the Markov parameters of the system:

.. math::

	\mathbf{\tilde{K}_{r}} \left( t_{k} \right) = \mathbf{C_{d}}\mathbf{A_{d}}^{k}\mathbf{B_{d}}~~,

where :math:`t_{k}=k\Delta t` for :math:`k=0,~1,~2,~\ldots` with :math:`\Delta t` being the sampling period.  The above equation does not include the feedthrough matrix as it results in an infinite value at :math:`t=0` and in order to keep the causality of the system.

The most common algorithm to obtain the realization is to perform a Singular Value Decomposition (SVD) on the Hankel matrix of the impulse response function as proposed by Kung :cite:`Kung1978`.  The order of the system and state-space parameters are determined from the number of significant values and the factors of the SVD.  Performing an SVD produces:

.. math::

	& H = \begin{bmatrix}
    		\mathbf{K_{r}}(2) & \mathbf{K_{r}}(3) & \ldots & \mathbf{K_{r}}(n) \\
       		\mathbf{K_{r}}(3) & \mathbf{K_{r}}(4) & \ldots & 0 \\
       		\vdots & \vdots & \ddots & \vdots \\
       		\mathbf{K_{r}}(n) & 0 & \cdots & 0
      	\end{bmatrix} &\\ 

.. math::

	& H = \mathbf{U} \Sigma \mathbf{V^{*}} &

where :math:`H` is the Hankel matrix and :math:`\Sigma` is a diagonal matrix containing the Hankel singular vales in descending order.  Examination of the Hankel singular values reveals there are only a small number of significant states and model reduction can be performed without a significant loss in accuracy :cite:`Taghipour2008,Kristiansen2005`.  Further detail into the SVD method and calculation of the state space parameters will not be discussed and the reader is referred to :cite:`Taghipour2008,Kristiansen2005`.

Wave Spectrum
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
The ability to generate regular waves provides an opportunity to observe the response of a model under specific conditions. Sea states with constant wave heights and periods are rarely found outside wave tank test. Normal sea conditions are more accurately represented by random-wave time series that model the superposition of various wave forms with different amplitudes and periods. This superposition of waves is characterized by a sea spectrum. Through statistical analysis, spectra are characterized by specific parameters such as significant wave height, peak period, wind speed, fetch length, and others. The common types of spectra that are used by the offshore industry are discussed in the following sections.  The general form of the sea spectrums available in WEC-Sim is given by:

.. math::

	S\left( f \right) = A f^{-5}\exp\left[-B f^{-4} \right]~~,

where :math:`f` is the wave frequency (in Hertz) and :math:`\exp` stands for the exponential function.

Pierson--Moskowitz
...............................
One of the simplest spectra was proposed by :cite:`PM`. It assumed that after the wind blew steadily for a long time over a large area, the waves would come into equilibrium with the wind. This is the concept of a fully developed sea, where a "long time" is roughly 10,000 wave periods, and a "large area" is roughly 5,000 wave-lengths on a side.  The spectrum is calculated from

.. math::
	& S\left( f \right) = \frac{\alpha_{PM}g^{2}}{\left( 2 \pi \right)^{4}}f^{-5}\exp\left[-\frac{5}{4} \left( \frac{f_{p}}{f}\right)^{4} \right]~~, &\\

	& A = \frac{\alpha_{PM}g^{2}}{\left( 2 \pi \right)^{4}},~~B = \frac{5}{4} {f_{p}}^{4}~~, &

where :math:`\alpha_{PM}` = 0.0081, :math:`g` is gravity, and :math:`f_{p}` is the peak frequency of the spectrum. However, this spectrum representation does not allow the user to define the significant wave height. To facilitate the creation of a power matrix, in WEC-Sim the :math:`\alpha_{PM}` coefficient was calculated such that the desired significant wave height of the sea state was met.  The :math:`\alpha_{PM}` fit was calculated as follows:

.. math::
	\alpha_{PM} = \frac{H_{m0}^{2}}{16\int_{0}^{\infty} S^{*} \left( f \right) df}~~
	
	S^{*}\left( f \right) = \frac{ g^{2} }{ (2\pi)^{4}} f^{-5}\exp\left[-\frac{5}{4} \left( \frac{f_{p}}{f}\right)^{4} \right]~~


Note that related to the spectrum is a series of characteristic numbers called the spectral moments. These numbers, denoted :math:`m_{k}~,~k=0, 1, 2,...` are defined as

.. math::
	m_{k} = \int_{0}^{\infty} f^{k} S \left( f \right) df ~~.

The spectral moment, :math:`m_{0}` is the variance of the free surface, which allows one to define

.. math::
	H_{m0} = 4 \sqrt{m_{0}}~~.

Bretschneider Spectrum
................................
This two-parameter spectrum is based on significant wave height and peak wave frequency.  For a given significant wave height, the peak frequency can be varied to cover a range of conditions including developing and decaying seas. In general, the parameters depend on wind speed (most important), wind direction, as well as fetch and locations of storm fronts. The spectrum is given as

.. math::
	& S\left( f \right) = \frac{{H_{m0}}^2}{4}\left(1.057f_{p}\right)^{4}f^{-5}\exp\left[-\frac{5}{4} \left( \frac{f_{p}}{f}\right)^{4} \right]~~, &\\
	
	& A =\frac{{H_{m0}}^2}{4}\left(1.057f_{p}\right)^{4} \approx \frac{5}{16} {H_{m0}}^2 {f_{p}}^{4}~~, &\\ 
	
	& B = \left(1.057f_{p}\right)^{4} \approx \frac{5}{4} {f_{p}}^{4}~~, &

where :math:`H_{m0}` is the significant wave height which is generally defined as the mean wave height of the one third highest waves.

JONSWAP (Joint North Sea Wave Project) Spectrum
....................................................
**WEC-Sim Default Spectrum**

The spectrum was purposed by Hasselmann et al. :cite:`HK`, and the original formulation was given as

.. math::
	& S\left( f \right) = \frac{ \alpha_{j} g^{2} }{ (2\pi)^{4}} f^{-5}\exp\left[-\frac{5}{4} \left( \frac{f_{p}}{f}\right)^{4} \right]\gamma^\Gamma \nonumber & \\ 
	
	&\Gamma = \exp \left[ -\left( \frac{\frac{f}{f_{p}}-1}{\sqrt{2} \sigma}\right)^{2} \right]~~, \sigma = \begin{cases} 0.07 & f \leq f_{p} \\0.09 & f > f_{p} \end{cases} ~~, &\\
	
	& A =\frac{ \alpha_{j} g^{2} }{ (2\pi)^{4}},~~B = \frac{5}{4} {f_{p}}^{4}~~, &

where :math:`\alpha_{j}` is a nondimensional variable that is a function of the wind speed and fetch length. 

Empirical fits were applied in an attempt to find a mean value that would capture the spectral shape of most measured sea states. To fit :math:`\alpha_{j}` to match the desired significant wave height the following calculation must be performed

.. math::
	\alpha_{j} = \frac{H_{m0}^{2}}{16\int_{0}^{\infty} S^{*} \left( f \right) df},

	S^{*}\left( f \right) = \frac{ g^{2} }{ (2\pi)^{4}} f^{-5}\exp\left[-\frac{5}{4} \left( \frac{f_{p}}{f}\right)^{4} \right]\gamma^\Gamma ~~.

**Spectrum purposed at ITTC**

Another form of JONSWAP spectrum was purposed at the 17th International Towing Tank Conference (ITTC). It was defined as

.. math::

	& S\left( f \right) = \frac{155 }{ \left( 2\pi \right)^{4}} \frac{H_{m0}^{2}}{(0.834T_{p})^{4}} f^{-5}\exp\left[-\frac{5}{4} \left( \frac{f_{p}}{f}\right)^{4} \right]\gamma^\Gamma \nonumber & \\ 

	& \approx \frac{310 }{ \left( 2\pi \right)^{4}} {H_{m0}}^{2} {f_{p}}^{4} f^{-5}\exp\left[-\frac{5}{4} \left( \frac{f_{p}}{f}\right)^{4} \right]\gamma^\Gamma~~, &\\

	&\Gamma = \exp \left[ -\left( \frac{\frac{f}{f_{p}}-1}{\sqrt{2} \sigma}\right)^{2} \right]~~,~~ \sigma = \begin{cases} 0.07 & f \leq f_{p} \\ 0.09 & f > f_{p} \end{cases} ~~, \\

	& A =\frac{310 }{ \left( 2\pi \right)^{4}} {H_{m0}}^{2} {f_{p}}^{4},~~B = \frac{5}{4} {f_{p}}^{4}~~. &

Figure~\ref{fig:JONSWAP} shows the comparison of the JONSWAP spectrum obtained from the :math:`\alpha_{j}` fit and the ITTC description .  It is clear that the two methods have very good agreement.

.. figure:: _static/Jonswap.png

   Comparison of :math:`\alpha_{j}` fit to the ITTC description of the JONSWAP spectrum with :math:`H_{m0}` = 2 m and peak period (:math:`T_{p}`) of 8 sec.\label{fig:JONSWAP}}


Ramp Function
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
A ramp function (:math:`R_{f}`), necessary to avoid strong transient flows at the earlier time steps of the simulation, is used to calculate the wave excitation force. The ramp function is given by

.. math::

	R_{f}=\begin{cases}
	\frac{1}{2}(1+\cos(\pi+\frac{\pi t}{t_{r}}), & \frac{t}{t_{r}}<1\\
	1, & \frac{t}{t_{r}}\geq1
	\end{cases},

where :math:`t` is the simulation time and :math:`t_{r}` is the ramp time.

Power Take-off Forces
---------------------------
The PTO mechanism is represented as a linear spring-damper system, where the reaction force is given by: 

.. math::

	F_{PTO}=-K{}_{PTO}X_{rel}-C_{PTO}\dot{X}_{rel},

where :math:`K_{PTO}` is the stiffness of the PTO, :math:`C_{PTO}` is the damping of the PTO, and :math:`X_{rel}` and :math:`\dot{X}_{rel}` are the relative motion and velocity between two bodies.  The power consumed by the PTO is given by:

 .. math::
	
	P_{PTO} = -F_{PTO}\dot{X}_{rel}=\left(K_{PTO}X_{rel}\dot{X}_{rel}+C_{PTO}\dot{X}^{2}_{rel}\right).


However, the relative motion and velocity between two bodies is out of phase by :math:`\pi/2`, resulting in a time-averaged product of 0. This allows the absorbed power to be written as

.. math::
	P_{PTO} =C_{PTO}\dot{X}^{2}_{rel}.

Mooring Forces
-------------------------
The mooring load is represented using a linear quasi-static mooring stiffness, which can be calculated by

.. math::
	F_{m}=-K_{m}X-C_{m}\dot{X},

where :math:`K_{m}` and :math:`C_{m}` are the stiffness and damping matrices for the mooring system, and :math:`X` and :math:`\dot{X}` are the response and velocity of the body, respectively.

Damping Forces
-----------------------
The effect of damping to the system is included by specifying linear and quadratic damping term to the equation of motion,

 .. math::
	F_{v}=-C_{ld}\dot{X}+\frac{1}{2}C_{d}\rho A_{D}\dot{X}|\dot{X}|,

where :math:`C_{ld}` is the linear damping coefficient, :math:`C_{d}` is the (quadratic) viscous drag coefficient, :math:`\rho` is the fluid density, and :math:`A_{D}` is the characteristic area.

Generally, the effect of viscosity on the WEC dynamics needs to be considered as neglecting this effect may lead to an overestimation of the power generation of the system, particularly when a linear model is applied. A common way of modeling the viscous damping is to add a (Morison-equation-type) quadratic damping term to the equation of motion. The viscous drag coefficient for the device must be carefully selected :cite:`Li2012,Babarit2012`; however, it is dependent on device geometry, scale, and relative velocity between the body and the flow around it. The drag coefficient becomes much larger when the Reynolds and the Keulegan-Carpenter number are smaller. Note that empirical data on the drag coefficient can be found in various literature and standards. The available data may, however, be limited to existing simple geometries. For practical point absorber geometry, the hydrodynamic forces may have to be evaluated by conducting wave tank tests or prescribed motion computational fluid dynamic simulations.

References
--------------
.. bibliography:: WEC-Sim.bib
   :style: unsrt
