#!/bin/bash
[ -f aranet.sim.gz ] && zcat aranet.sim.gz > aranet.sim
../../bin/truncate -t 20 aranet
../../bin/layout -e aranet
../../bin/recoord -e aranet
python make_kin.py > aranet.kin
rm aranet.{full,icoord,iedges,ind,int} # intermediate files
rm aranet.{coord,edges} # final product files

