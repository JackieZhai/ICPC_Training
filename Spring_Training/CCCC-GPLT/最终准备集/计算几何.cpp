///计算几何相关


/** 多边形的面积：
 *  要求按照逆时针方向输入多边形顶点
 *  可以是凸多边形或凹多边形
 */
double area_of_polygon(int vcount, Lpoint plg[])
{
    int i;
    double s;
    if (vcount < 3)
    {
        return 0;
    }
    s = plg[0].y * (plg[vcount - 1].x - plg[1].x);
    for (i = 1; i < vcount; i++)
    {
        s += plg[i].y * (plg[(i - 1)].x - plg[(i + 1) % vcount].x);
    }
    return s / 2;
}


///求圆相交的面积
double Area_of_overlap(Point c1, double r1, Point c2, double r2)
{
    double d = dist(c1, c2);
    if (r1 + r2 < d + eps)
    {
        return 0;
    }
    if (d < fabs(r1 - r2) + eps)
    {
        double r = min(r1, r2);
        return PI * r * r;
    }
    double x = (d * d + r1 * r1 - r2 * r2) / (2 * d);
    double t1 = acos(x / r1);
    double t2 = acos((d - x) / r2);
    return r1 * r1 * t1 + r2 * r2 * t2 - d * r1 * sin(t1);
}



/** 求矩形相交的面积
 *  x[]、y[]存储矩阵对角线顶点（只需要任意一条）
 */
double Area_of_overlap_rec(double x[], double y[])
{
    //  将两个矩形全部统一为主对角线
    sort(x, x + 2);
    sort(x + 2, x + 4);
    sort(y , y + 2);
    sort(y + 2, y + 4);

    if (x[1] <= x[2] || x[0] >= x[3] || y[0] >= y[3] || y[1] <= y[2])   //  相离
    {
        return 0.0;
    }
    else
    {
        sort(x, x + 4);
        sort(y, y + 4);
        return (x[2] - x[1]) * (y[2] - y[1]);
    }
}
