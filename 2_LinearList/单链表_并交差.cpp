// 伪代码

// union	英[ˈju:niən]	美[ˈjunjən]
// n.	同盟，联盟; 协会，工会; 联合，团结;
// adj.	工会的;
// [例句]	I feel that women in all types of employment can benefit from joining a union.
// 			我认为女性无论从事什么工作，加入工会都是有好处的。
// [其他]	复数：unions
void union (LinkList *L1,LinkList *L2,LinkList *&L3)
{
    LinkList *p1 = L1 -> next, *p2 = L2 -> next, *s, *r;

    L3 = new LinkList;
    r = L3;

    while (p1! = NULL && p2 != NULL)
    {
        if (p1 -> data < p2 -> data)
        {
            s = new LinkList;
            s -> data = p1 -> data;
            r -> next = s;
            r = s;
            p1 = p1 -> next;
        }
        else if (p1 -> data > p2 -> data)
        {
            s = new LinkList;
            s -> data = p2 -> data;
            r -> next = s;
            r = s;
            p2 = p2 -> next;
        }
        else
        {
            s = new LinkList;
            s -> data = p1 -> data;
            r -> next = s;
            r = s;
            // 两个相等就同时取下一个元素
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
    }
    // 判断为空的链
    if (p2 != NULL)
    {
    	p1 = p2;
    }
    while (p1!=NULL)
    {
        s = new LinkList;
        s -> data = p1 -> data;
        r -> next = s;
        r = s;
        p1 = p1 -> next;
    }
    r->next=NULL;
}

// intersect	英[ˌɪntəˈsekt]	美[ˌɪntərˈsekt]
// vt.	横断，横切，横穿;
// vt.	（指线条、道路等） 相交，交叉;
// [例句]	The orbit of this comet intersects the orbit of the Earth
// 			这颗彗星的轨道与地球的轨道交叉。
// [其他]	第三人称单数：intersects 现在分词：intersecting 过去式：intersected 过去分词：intersected
void intersect (LinkList *L1,LinkList *L2,LinkList *&L3)
{
    LinkList *p1 = L1 -> next, *p2 , *s, *r;
    L3 = new LinkList;
    r = L3;
    while (p1 != NULL)
    {
        p2 = L2 -> next;
        // 以L1某个p1为基准，判断第一个大于等于p1的p2是否与p1相等
        while (p2 != NULL && p2 -> data < p1 -> data)
        {
            p2 = p2 -> next;
        }
        // 相等即满足条件，放入L3中
        if (p2 != NULL && p2 -> data == p1 -> data) /*若p1 结点值在B中*/
        {
            s = new LinkList;
            s -> data = p1 -> data;
            r -> next = s;
            r = s;
        }
        p1 =p1 ->next;
    }
    r ->next=NULL;
}

// subtraction	英[səb'trækʃn]	美[səbˈtrækʃən]
// n.	减去; 减，减法; 减除法;
// [例句]	There will be simple tests in addition, subtraction, multiplication and division.
// 			会有对加、减、乘、除运算的简单测试。
// [其他]	复数：subtractions
void subs (LinkList *L1,LinkList *L2,LinkList *&L3)
{
    LinkList *p1 = L1 -> next, *p2, *s, *r;
    L3 = new LinkList;
    r = L3;
    while (p1 != NULL)
    {
        p2 = L2 -> next;
        // 以L1某个p1为基准，判断第一个大于等于p1的p2是否与p1相等
        while (p2 != NULL && p2 -> data < p1 -> data)
        {
            p2 = p2 -> next;
        }
        // 不相等即满足条件（p1的值不在L2中），放入L3中
        if (!(p2 != NULL && p2 -> data == p1 -> data))
        {
            s = new LinkList;
            s -> data = p1 -> data;
            r -> next = s;
            r = s;
        }
        p1 = p1 -> next;
    }
    r->next=NULL;
}
