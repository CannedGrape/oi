const   ff='classroom';
        maxn=1000000;
var	a,line,de,lt,rt,mi,lc,rc:array[0..maxn*2+10]of longint;
        n,i,m,d,s,t,pl:longint;

function min(x,y:longint):longint;
begin
if x>y then exit(y) else exit(x);
end;

procedure build(l,r,p:longint);
begin
lt[p]:=l;rt[p]:=r;mi[p]:=(l+r)shr 1;
if l=r then
	line[p]:=a[l];
if (l<r)then begin
	inc(pl);lc[p]:=pl;build(l,mi[p],lc[p]);
        inc(pl);rc[p]:=pl;build(mi[p]+1,r,rc[p]);
	line[p]:=min(line[lc[p]],line[rc[p]]);
	end;
end;

procedure del(d,s,t,p:longint);
begin

inc(de[lc[p]],de[p]);
inc(de[rc[p]],de[p]);
dec(line[p],de[p]);
de[p]:=0;
if (s<=lt[p])and(rt[p]<=t)then begin
	inc(de[lc[p]],d);
	inc(de[rc[p]],d);
	dec(line[p],d);
	if line[p]<0 then begin
		writeln('-1');writeln(i);
		close(input);close(output);
		halt;
		end;
	end
else begin
	if (s<=mi[p])and(lt[p]<=t) then del(d,s,t,lc[p]);
	if (s<=rt[p])and(mi[p]<t) then del(d,s,t,rc[p]);
	line[p]:=min(line[lc[p]],line[rc[p]]);
	end;
end;

begin
assign(input,ff+'.in');reset(input);
assign(output,ff+'.out');rewrite(output);
readln(n,m);
for i:=1 to n do read(a[i]);
pl:=1;build(1,n,1);
for i:=1 to m do begin
        read(d,s,t);
        del(d,s,t,1);
	end;
writeln('0');
close(input);close(output);
end.
