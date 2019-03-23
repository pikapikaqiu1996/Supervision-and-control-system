/*
 * 
 * Define Draw Objects
 *
 */


class CDrawObject : public CObject
{
private:
	COLORREF m_PenColor;//图元颜色
	COLORREF m_FillColor;//图元颜色
	COLORREF m_TextColor;//图元颜色
    int      m_nPenWidth;
    CPoint   m_Point;
public:
	bool m_bSelected;
	long m_nStyle;//图元类型
	bool m_bAlarm;
	COLORREF m_FlashTextColor;//图元颜色
	CDrawObject(){m_bSelected = false;};

	void SetPenColor(COLORREF color);//设置图元颜色
	void SetFillColor(COLORREF color);//设置图元颜色
	void SetTextColor(COLORREF color);//设置图元颜色
	void SetPenWidth(int nWidth);
	COLORREF GetPenColor();//获得图元颜色
	COLORREF GetFillColor();//获得图元颜色
	COLORREF GetTextColor();//获得图元颜色
	int      GetPenWidth();
	void HotPoint(CDC* pDC, long x, long y);
	bool AtPoint(long x1, long y1, long x, long y);//判断两点位置关系
	bool AtLine(long x1, long y1, long x2, long y2, long x, long y);//判断点和直线的位置关系
    virtual int  distance(){return 0;};
    virtual void SetMark(int Mark){};
    virtual int  GetMark(){return 0;};
	virtual void Selected(CDC* pDC, bool select){};//绘制（取消）选择标志
	virtual void Draw(CDC* pDC){};//绘制图元
	virtual void FlashDraw(CDC* pDC){};//绘制图元
	virtual int  SelectAt(long x, long y){return 0;};//判断是否选择图元
	virtual void MoveAt(CDC* pDC, int flags, long x, long y){};//以指定方式移动图元
	virtual int  NewPoint(long x, long y){return 0;};//图形对象第一点坐标，如果返回false则结束绘图
	virtual int  AddPoint(long x, long y){return 0;};//图形对象下一点坐标，如果返回false则结束绘图
	virtual void HotPoints(CDC* pDC){};//绘制热点
	virtual void Serialize(CArchive& ar){};
	DECLARE_SERIAL(CDrawObject);//用于实现串行化输入输出
};

class CDrawLine : public CDrawObject
{
private:
	long m_x1, m_y1, m_x2, m_y2;
	long m_oldx, m_oldy;
    int  m_nN;
public:
	CDrawLine(COLORREF color = RGB(255,0,0),COLORREF textcolor=RGB(0,0,255),int nPenWidth=1);
    void SetMark(int Mark);
    int  GetMark();
	void Selected(CDC* pDC, bool select);
	void Draw(CDC* pDC);
	void FlashDraw(CDC* pDC);//绘制图元
    int  distance();
	int  SelectAt(long x, long y);
	void MoveAt(CDC* pDC, int flags, long x, long y);
	int  NewPoint(long x, long y);
	void HotPoints(CDC* pDC);//绘制热点
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CDrawLine);
};




class CDrawCircle : public CDrawObject
{
private:
	long m_x, m_y, m_r;
	long m_oldx, m_oldy;
    int  m_nN;

public:
	CDrawCircle(COLORREF color = RGB(255,0,0),COLORREF fillcolor=RGB(255,255,0),COLORREF textcolor=RGB(0,0,255));
    void SetMark(int Mark);
    int  GetMark();
	int  distance();
	void Selected(CDC* pDC, bool select);
	void Draw(CDC* pDC);
	void FlashDraw(CDC* pDC);//绘制图元
	int  SelectAt(long x, long y);
	void MoveAt(CDC* pDC, int flags, long x, long y);
	int  NewPoint(long x, long y);
	void HotPoints(CDC* pDC);//绘制热点
	bool AtinSide(long x, long y);//判断点是否在曲线上
	void Serialize(CArchive& ar);
	DECLARE_SERIAL(CDrawCircle);
};



