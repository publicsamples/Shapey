import("stdfaust.lib");

Q = hslider("Q",1,1,10,0.01);
normFreq = hslider("freq",0.5,0,1,0.001);


process = ve.diodeLadder(normFreq,Q), ve.diodeLadder(normFreq,Q);
