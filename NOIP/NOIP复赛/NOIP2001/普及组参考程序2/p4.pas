const
	maxn=100;
var
	cityno:integer;
	px,py,value:array[1..4*maxn] of real;
	roadfee:array[1..maxn] of real;
	mk:array[1..4*maxn] of boolean;
	city:array[1..4*maxn] of integer;
	flyfee:real;
	A,B,n:integer;	

function IsZero(x:real):boolean;
begin
	if( (x>1e-12) or (x<-1e12) ) then
		IsZero:=false
	else
		IsZero:=true;
end;

function distance(x1,y1,x2,y2:real):real;
begin
	distance:=sqrt(sqr(x1-x2)+sqr(y1-y2));
end;

function CuiZhi(x0,y0,x1,y1,x2,y2:real):boolean;
begin
	CuiZhi:=IsZero((y1-y0)*(y2-y0)+(x1-x0)*(x2-x0));
end;

function CountDistance(i,j:integer):real;
begin
	if(city[i]<>city[j]) then
		CountDistance:=distance(px[i],py[i],px[j],py[j])*flyfee
	else
		CountDistance:=distance(px[i],py[i],px[j],py[j])*roadfee[city[i]];
end;

procedure iswap(var x,y:integer);
var tmp:integer;
begin
	tmp:=x;
	x:=y;
	y:=tmp;
end;

procedure Init;
var
	i:integer;
	i0,i1,i2,i3:integer;
begin
	readln(cityno,flyfee,A,B);
	n:=cityno*4;
	for i:=1 to cityno do
	begin
		i0:=4*i;
		i1:=i0-1;
		i2:=i0-2;
		i3:=i0-3;
		readln(px[i0],py[i0],px[i1],py[i1],px[i2],py[i2],roadfee[i]);
		if( not CuiZhi(px[i0],py[i0],px[i1],py[i1],px[i2],py[i2]) ) then
		begin
			if( CuiZhi(px[i1],py[i1],px[i0],py[i0],px[i2],py[i2]) ) then
				iswap(i1,i0)
			else
				iswap(i2,i0);
		end;
		px[i3]:=px[i1]+px[i2]-px[i0];
		py[i3]:=py[i1]+py[i2]-py[i0];			
		city[i0]:=i;
		city[i1]:=i;
		city[i2]:=i;
		city[i3]:=i;
		if( (i=A) or (i=B) ) then
			roadfee[i]:=0;
	end;

end;

procedure Dijkstra;
var
	i,u,v:Integer;
begin
	for i:=1 to n do
		value[i]:=1e12;
	A:=A*4;
	B:=B*4;
	value[A]:=0;
	u:=A;
	fillchar(mk,sizeof(mk),false);
	while(u<>B) do
	begin
		for v:=1 to n do
			if( (not mk[v]) and (value[u]+CountDistance(u,v)<value[v]) ) then
				value[v]:=value[u]+CountDistance(u,v);
		mk[u]:=true;
		u:=-1;
		for i:=1 to n do 
			if( (not mk[i]) and ( (u<0) or (value[i]<value[u]) ) ) then
				u:=i;
	end;
end;

var
	filename:string;
	caseno:integer;	
begin
	readln(filename);
	assign(input,filename);
	reset(input);
	readln(caseno);
	while(caseno>0) do
	begin
		dec(caseno);
		Init;
		Dijkstra;
		writeln(value[B]:0:2);
	end;
	close(input);
end.