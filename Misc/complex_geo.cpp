//THIS DOES NOT GO WELL WITH INTS
typedef complex<double> point;
#define x real()
#define y imag()

// vector addition and subtraction
cout << a + b << endl;   // (5,-5)

// scalar multiplication
cout << 3.0 * a << endl; // (9,6)

//dot product: (conj(a) * b).x
//cross product: (conj(a) * b).y
//Euclidean distance: abs(a - b)
//Slope of line (a, b): tan(arg(b - a))
//Polar to cartesian: polar(r, theta)
//Cartesian to polar: point(abs(p), arg(p))
//Rotation about the origin: a * polar(1.0, theta)
//Rotation about pivot p: (a-p) * polar(1.0, theta) + p
//Angle ABC: abs(remainder(arg(a-b) - arg(c-b), 2.0 * M_PI))
//remainder normalizes the angle to be between [-PI, PI]. Thus, we can get the positive non-reflex angle by taking its abs value.
//Project p onto vector v: v * dot(p, v) / norm(v);
//Project p onto line (a, b): a + (b - a) * dot(p - a, b - a) / norm(b - a)
//Reflect p across line (a, b): a + conj((p - a) / (b - a)) * (b - a)
//Intersection of line (a, b) and (p, q):

point intersection(point a, point b, point p, point q) {
  double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
  return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}