clear all


% Nombre de bit en entrée et en sortie des blocs prop. et integ. du filtre
N_filter_in=5; Nprop_in=5; Nprop_out=9;


  Kprop_num=40;% val init : 20
  Kprop_den=2^5; 
  Kint_num=400;%val init : 400
  Kint_den=2^12; 

TDC=[1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]; tau=30e-12;

f0_dco0=141.625e6; gain_dco0=199300; % comme chez Eldar

freq_ref=2.227965e8;



% fr??quences initiales des DCOs et les gains de DCO avec dispersion
f0_dco=f0_dco0+gain_dco0*rand();
gain_dco=gain_dco0*(1+0.00*(rand-0.5));

integrator_init_state_max=2^10-1; 
integrator_init_state_min=0;


% phases initiales des DCo
phi0=rand*2*pi;
integrator_init_state=Kint_den*(integrator_init_state_min+ 0.1*(integrator_init_state_max-integrator_init_state_min));


    

