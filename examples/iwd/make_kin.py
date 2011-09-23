# For this network, the example multi-level coarsening approach makes the network
# look much clumpier and messier -- overrated.  :)
#
# ../../bin/truncate -t 20 aranet
# ../../bin/layout -e aranet
# ../../bin/recoord -e aranet
# python make_kin.py > ~/windesk/aranet.kin
# rm aranet.[^s]*


from bisect import bisect_left
rootname = "aranet"

nodes = {} # {"name": (x,y,z)}
for line in open(rootname+".coord"):
    name, x, y, z = line.rstrip().split("\t")
    nodes[name] = (x,y,z)

colors = "purple,blue,sky,cyan,sea,green,lime,yellow,gold,orange,red".split(",")
ranges = [float(x)/(len(colors)-1) for x in xrange(len(colors))]

print "@vectorlist {edges} color= gray width= 1 alpha= 0.25"
for line in open(rootname+".edges"):
    node1, node2, weight = line.rstrip().split("\t")
    weight = float(weight)
    x1,y1,z1 = nodes[node1]
    x2,y2,z2 = nodes[node2]
    idx = bisect_left(ranges, weight)
    try: color = colors[idx]
    except:
        print weight, idx, ranges
        raise
    print "{%s}P %s %s %s {%s} %s %s %s %s" % (node1, x1, y1, z1, node2, color, x2, y2, z2)

print "@1aspect {A}"
print "@2aspect {B}"
print "@balllist {nodes} radius= 0.25 nohighlight"
for node, (x,y,z) in nodes.iteritems():
    print "{%s} (AB) %s %s %s" % (node, x, y, z)

