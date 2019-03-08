program t2001_4;
const maxn=100;
type ZuoBiao=record
         x,y:integer;
     end;
     quee=record
         num:integer;
         cost:real;
     end;
var s,t,a,b,i,j,k,n,n1:integer;
    di,minv:real;
    rail:array[1..maxn]of integer;
    min:array[1..4*maxn]of quee;
    sta:array[1..4*maxn]of ZuoBiao;

function distance(a,b:ZuoBiao):real;
begin
    distance:=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
end;

function dirct(i,j:integer):real;
var k,per:integer;
begin
     k:=(i-1) div 4+1;
     if (((i-1) div 4)=((j-1) div 4))  and (rail[k]<t) then
          per:=rail[k]
     else per:=t;
     dirct:=distance(sta[i],sta[j])*per;
end;

procedure fourth(a,b,c:ZuoBiao;var d:ZuoBiao);
var m,n:real;
begin
    if b.x=c.x then begin
          d.x:=a.x;
          d.y:=b.y+(a.y-c.y)*(d.x-b.x) div (a.x-c.x);
      end
    else if a.x=c.x then begin
          d.x:=b.x;
          d.y:=a.y+(b.y-c.y)*(d.x-a.x) div (b.x-c.x);
      end
    else begin
          d.x:=(b.y-a.y)*(b.x-c.x)*(a.x-c.x)+a.x*(b.y-c.y)*(a.x-c.x)-b.x*(a.y-c.y)*(b.x-c.x);
          d.x:=d.x div ((b.y-c.y)*(a.x-c.x)-(a.y-c.y)*(b.x-c.x));
          d.y:=a.y+(b.y-c.y)*(d.x-a.x) div (b.x-c.x);
      end;
end;

function three_one(a,b,c:ZuoBiao):ZuoBiao;
var d:ZuoBiao;ab,bc,ac:real;
begin
     ab:=distance(a,b);
     bc:=distance(b,c);
     ac:=distance(a,c);
     if (ab>bc) and (ab>ac) then
            fourth(a,b,c,d)
     else if (bc>ac) and (bc>ab) then
            fourth(b,c,a,d)
     else   fourth(a,c,b,d);
     three_one:=d;
end;

procedure init;
var d:ZuoBiao;
begin
    readln(s,t,a,b);
    for i:=1 to s do begin
        for j:=1 to 3 do begin
            read(sta[(i-1)*4+j].x);
            read(sta[(i-1)*4+j].y);
          end;
        readln(rail[i]);
        sta[(i-1)*4+4]:=three_one(sta[(i-1)*4+1],sta[(i-1)*4+2],sta[(i-1)*4+3]);
     end;
end;

procedure addque(n:integer;c:real);
var p,a,a1:integer;b,b1:real;
begin
    p:=1;
    while (min[p].cost<>0) and (min[p].cost<=c) do
       p:=p+1;
    a:=min[p].num;b:=min[p].cost;
    min[p].num:=n;min[p].cost:=c;
    while b<>0 do begin
        p:=p+1;
        a1:=min[p].num;b1:=min[p].cost;
        min[p].num:=a;min[p].cost:=b;
        a:=a1;b:=b1;
    end;
end;

procedure sort(n:integer);
var i,j:integer;temp:quee;
begin
    for i:=n to 4*s-2 do
      for j:=i+1 to 4*s-1 do
         if min[i].cost>min[j].cost then begin
           temp:=min[i];min[i]:=min[j];min[j]:=temp;end;
end;

begin
     assign(input,'input4.dat');
     reset(input);
     assign(output,'output4.dat');
     rewrite(output);
     readln(n);
     for n1:=1 to n do begin
        init;
        if a=b then writeln(0.0:0:1)
        else begin
            minv:=1.0e20;
            for j:=1 to 4 do begin
                fillchar(min,sizeof(min),0);
                for i:=1 to (a-1)*4+j-1 do
                    addque(i,dirct((a-1)*4+j,i));
                for i:=(a-1)*4+j+1 to 4*s do
                    addque(i,dirct((a-1)*4+j,i));
                for i:=1 to 4*s-2 do begin
                    for k:=i+1 to 4*s-1 do begin
                        di:=dirct(min[i].num,min[k].num);
                        if (min[i].cost+di)<min[k].cost then
                            min[k].cost:=min[i].cost+di;
                    end;
                    sort(i+1);
                end;
                for k:=1 to 4*s-1 do
                  if (min[k].cost<minv) and ((min[k].num-1) div 4=b-1) then
                      minv:=min[k].cost;
            end;
            writeln(minv:0:1);
         end;
     end;
     close(input);
     close(output);
end.
