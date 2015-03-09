

% '  %**' = not used.
hydroData = struct('properties'           , struct('name'      , 'NONE'                                     ,...                                %name of body
                                                   'bodyNumber', 0                                          ,...                                %body number in BEM simulation 0-indexed
                                                   'cg'        , [0, 0, 0]                                  ,...                                %location of center of gravity [x,y,z] in m
                                                   'cb'        , [0, 0, 0]                                  ,...                                  %**location of center of buoyancy [x,y,z] in m
                                                   'dispVol'   , 0                                                              ),...           %displaced volume in m^3
                   'hydro_coeffs'         , struct('ex'        , struct('mag'  , 0                          , ...                                 %**magnitude of excitation force, numFreq x 6 matrix
                                                                        'phase', 0                          , ...                                 %**phase of excitation force, numFreq x 6 matrix
                                                                        're'   , 0                          , ...                               %real component of excitation force, numFreq x 6 matrix
                                                                        'im'   , 0                                  ), ...                      %imaginary component of excitation force, numFreq x 6 matrix
                                                   'am'        , struct('all'  , 0                          , ...                               %frequency dependent added mass, 6 x 6 x numFreq
                                                                        'inf'  , 0                          , ...                               %added mass at infinite frequency, 6 x 6 matrix
                                                                        'comps', struct                             ), ...                        %**component vectors for frequency dependent added mass, structure containing 36 vectors length numFreq
                                                   'rd'        , struct('all'  , 0                          , ...                               %frequency dependent radiation damping, 6 x 6 x numFreq
                                                                        'comps', struct                             ), ...                        %**component vectors for frequency dependent radiation damping, structure containing 36 vectors length numFreq
                                                   'k'         , 0                                          , ...                               %linear hydrostatic restoring coefficient matrix, 6x6
                                                   'irf'       , struct('K'    , 0                          , ...                               %irf K
                                                                        'L'    , 0                          , ...                                 %**irf L
                                                                        'comps', struct('K', struct, ...                                          %**components of K
                                                                                        'L', struct)                ), ...                        %**components of L
                                                                        't'    , 0                          , ...                                 %**convolution integral time in [s]
                                                                        'w'    , 0                                              ), ...            %**numbver of ferquencies used in irf calculation
                   'simulation_parameters', struct('T'         , 0                                          , ...                                 %**period vector in s
                                                   'w'         , 0                                          , ...                               %frequency vector in rad/s 
                                                   'g'         , 0                                          , ...                                 %**gravitational acceleration in m/s^2
                                                   'rho'       , 0                                          , ...                                 %**water density in kg/m^3 
                                                   'wDepth'    , 0                                          , ...                                 %**water depth in m 
                                                   'wDir'      , 0                                                              )           );    %**wave direction in rad
                                          
hydroForce = struct('fAddedMass'         , zeros(6)                                   , ...
                    'fDamping'           , zeros(6)                                   , ...
                    'linearHydroRestCoef', zeros(6)                                   , ...
                    'visDampingCoef'     , zeros(6)                                   , ...
                    'linearDamping'      , zeros(6)                                   , ...
                    'fExt'               , struct('re'            , zeros(1,6)  , ...
                                                  'im'            , zeros(1,6)       ), ...
                    'irkb'               , zeros(irf.w, 6, 6)                         , ...
                    'storage'            , struct('mass'          , 0           , ...
                                                  'momOfInertia'  , [0 0 0]     , ...
                                                  'fAddedMass'    , zeros(6)    , ...
                                                  'forceRadiation',zeros(ndt,6)      )     );          
                                              
                                              
                       