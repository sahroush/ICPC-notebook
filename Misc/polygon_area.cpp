vector<Point> points(n);
for (auto &p : points) { cin >> p; }
points.push_back(points[0]);

long long area = 0;
for (int i = 0; i < points.size(); i++) {
    area +=
        (1LL * points[i].x * points[i + 1].y - 1LL * points[i].y * points[i + 1].x);
}
cout << labs(area) << '\n';