using Point = complex<double>;
pair<double, double> unpack(Point P) {
    return {P.real(), P.imag()};
}
const double EPS = 1e-10;

inline bool equal(const double &a, const double &b) {
    return fabs(a - b) < EPS;
}

struct Line {
    // 点a, bを通る直線
    Point a, b;
    Line() = default;
    Line(Point _a, Point _b) : a(_a), b(_b) {
    }
    // Ax + By = C
    Line(double A, double B, double C) {
        if (equal(A, 0)) {
            a = Point(0, C / B), b = Point(1, C / B);
        } else if (equal(B, 0)) {
            b = Point(C / A, 0), b = Point(C / A, 1);
        } else {
            a = Point(0, C / B), b = Point(C / A, 0);
        }
    }
    tuple<double, double, double> coefficient() {
        // Ax + By = C のA, B, Cを返す
        auto [x1, y1] = unpack(a);
        auto [x2, y2] = unpack(b);
        return {y2 - y1, x1 - x2, x1 * y2 - y1 * x2};
    }
};

struct Circle {
    Point P;
    double r;

    Circle() = default;

    Circle(Point p, double _r) : P(p), r(_r) {
    }
};

Line intersection_line(Circle c1, Circle c2) {
    auto [p1, r1] = c1;
    auto [p2, r2] = c2;
    auto [x1, y1] = unpack(p1);
    auto [x2, y2] = unpack(p2);

    return Line(2 * (x2 - x1), 2 * (y2 - y1), (x1 + x2) * (x1 - x2) + (y1 + y2) * (y1 - y2) + (r2 + r1) * (r2 - r1));
}

pair<Point, Point> intersection_point(Circle circle, Line line) {
    auto [a, b, c] = line.coefficient();
    auto [p, r] = circle;
    auto [x, y] = unpack(p);
    double d = abs(a * x + b * y + c);
    double t = sqrt((a * a + b * b) * r * r - d * d);
    return {{(a * d - b * t) / (a * a + b * b) + x, (b * d + a * t) / (a * a + b * b) + y},
            {(a * d + b * t) / (a * a + b * b) + x, (b * d - a * t) / (a * a + b * b) + y}};
}

pair<Point, Point> intersection_point(Circle c1, Circle c2) {
    auto [p1, r1] = c1;
    auto [p2, r2] = c2;
    auto [x1, y1] = unpack(p1);
    auto [x2, y2] = unpack(p2);

    Line line(2 * (x2 - x1), 2 * (y2 - y1), (x1 + x2) * (x1 - x2) + (y1 + y2) * (y1 - y2) + (r2 + r1) * (r2 - r1));
    return intersection_point(c1, line);
}

inline double dist(Point &s, Point &t) {
    return abs(s - t);
}

Point mid_point(Point &s, Point &t) {
    return (s + t) / 2.0;
}