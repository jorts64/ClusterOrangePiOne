difference() {
    cube([140,38,3]);
    for( x = [25 : 15 : 115])
       translate([x,2,-1]) cube([3,19,5]);

}