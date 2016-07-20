int n, m;
int a[500][500];
int t[4*500+1][4*500+1];

void build (int vx, int xl, int xr, int vy, int yl, int yr) {
	if (xl == xr)
		if (yl == yr)
			t[vx][vy] = a[xl][yl];
		else {
			int ym = (yl + yr) >> 1;
			build (vx, xl, xr, vy+vy, yl, ym);
			build (vx, xl, xr, vy+vy+1, ym+1, yr);
			t[vx][vy] = min (t[vx][vy+vy], t[vx][vy+vy+1]);
		}
	else {
		int xm = (xl + xr) >> 1;
		build (vx+vx, xl, xm, vy, yl, yr);
		build (vx+vx+1, xm+1, xr, vy, yl, yr);
		for (int i=0; i<=500*4; ++i)
			t[vx][i] = min (t[vx+vx][i], t[vx+vx+1][i]);
	}
}

int tree_min (int vx, int xl, int xr, int txl, int txr, int vy, int yl, int yr, int tyl, int tyr) {
	if (xl == txl && xr == txr)
		if (yl == tyl && yr == tyr)
			return t[vx][vy];
		else {
			int tym = (tyl + tyr) >> 1;
			if (yr <= tym)
				return tree_min (vx, xl, xr, txl, txr, vy+vy, yl, yr, tyl, tym);
			else if (yl > tym)
				return tree_min (vx, xl, xr, txl, txr, vy+vy+1, yl, yr, tym+1, tyr);
			else
				return min (
					tree_min (vx, xl, xr, txl, txr, vy+vy, yl, tym, tyl, tym),
					tree_min (vx, xl, xr, txl, txr, vy+vy+1, tym+1, yr, tym+1, tyr)
				);
		}
	else {
		int txm = (txl + txr) >> 1;
		if (xr <= txm)
			return tree_min (vx+vx, xl, xr, txl, txm, vy, yl, yr, tyl, tyr);
		else if (xl > txm)
			return tree_min (vx+vx+1, xl, xr, txm+1, txr, vy, yl, yr, tyl, tyr);
		else
			return min (
				tree_min (vx+vx, xl, txm, txl, txm, vy, yl, yr, tyl, tyr),
				tree_min (vx+vx+1, txm+1, xr, txm+1, txr, vy, yl, yr, tyl, tyr)
			);
	}
}