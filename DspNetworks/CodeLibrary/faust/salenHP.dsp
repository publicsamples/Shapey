import("stdfaust.lib");

Q = hslider("Q",1,0.5,10,0.01);
normFreq = hslider("freq",0.5,0,1,0.001);


process = ve.sallenKey2ndOrderHPF(normFreq,Q), ve.sallenKey2ndOrderHPF(normFreq,Q);
