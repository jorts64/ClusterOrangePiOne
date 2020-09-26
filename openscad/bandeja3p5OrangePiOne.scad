difference(){
    cube([97,102,15]);
    union(){
        translate([2,-1,2]) cube([93,104,23]);
        translate ([-1,25,5]) rotate ([0,90,0]) cylinder(r=1.4,h=5, $fn=48); 
        translate ([-1,75,5]) rotate ([0,90,0]) cylinder(r=1.4,h=5, $fn=48); 
        translate ([95,25,5]) rotate ([0,90,0]) cylinder(r=1.4,h=5, $fn=48); 
        translate ([95,75,5]) rotate ([0,90,0]) cylinder(r=1.4,h=5, $fn=48); 
    }

}
translate([30,21,1]) difference(){
    cylinder(r=2, h=5, $fn=96);
    cylinder(r=1, h=5, $fn=96);  
}
translate([30,85,1]) difference(){
    cylinder(r=2, h=5, $fn=96);
    cylinder(r=1, h=5, $fn=96);  
}
translate([72,21,1]) difference(){
    cylinder(r=2, h=5, $fn=96);
    cylinder(r=1, h=5, $fn=96);  
}
translate([72,85,1]) difference(){
    cylinder(r=2, h=5, $fn=96);
    cylinder(r=1, h=5, $fn=96);  
}