import("stdfaust.lib");

Q = hslider("Q",1,0.5,10,0.01);
normFreq = hslider("freq",0.5,0,1,0.001);


process = ve.moogLadder(normFreq,Q), ve.moogLadder(normFreq,Q);
