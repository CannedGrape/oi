type
	v=longint;
	e=int64;
var
	n,m,q,i,qx,qy,bianshu,zuixiao,tem,chudui,head,tail:v;
	flag:boolean;
	x,y,z,daoda,shangyi,changdu:array[0..100001]of v;
	que:array[0..500001]of v;
	fa,last,lushangzuixiao,jingguo:array[0..100001]of v;
function min(xx,yy:v):v;
begin
	if xx<yy then exit(xx);
	exit(yy);
end;
procedure qs(l,r:v);
var ii,jj,mid,t:v;
begin
	ii:=l;
	jj:=r;
	mid:=z[(ii+jj) shr 1];
	repeat
		while z[ii]>mid do
			inc(ii);
		while z[jj]<mid do
			dec(jj);
		if ii<=jj then
			begin
				t:=x[ii];
				x[ii]:=x[jj];
				x[jj]:=t;
				t:=y[ii];
				y[ii]:=y[jj];
				y[jj]:=t;
				t:=z[ii];
				z[ii]:=z[jj];
				z[jj]:=t;
				inc(ii);
				dec(jj);
			end;
	until ii>jj;
	if ii<r then qs(ii,r);
	if l<jj then qs(l,jj);
end;
function getf(xx:v):v;
begin
	if fa[xx]=xx then exit(xx);
	fa[xx]:=getf(fa[xx]);
	exit(fa[xx]);
end;
{procedure dfs(now,mudi,xunwenshu,lushangzuixiao:v);
var tem:v;
begin
	if now=mudi then
		begin
			flag:=true;
			zuixiao:=lushangzuixiao;
			exit;
		end;
	tem:=last[now];
	//tem:=now;
	while tem>0 do
		begin
			if jingguo[daoda[tem]]<>xunwenshu then
				begin
					jingguo[daoda[tem]]:=xunwenshu;
					
					jingguo[daoda[tem]]:=0;
				end;
			tem:=shangyi[tem];
		end;
end;}
begin
	assign(input,'truck.in');
	assign(output,'truck.out');
	reset(input);
	rewrite(output);
	bianshu:=0;
	//fillchar(last,sizeof(last),0);
	read(n,m);
	for i:=1 to n do
		begin
			fa[i]:=i;
			jingguo[i]:=0;
			last[i]:=0;
		end;
	for i:=1 to m do
		begin
			shangyi[i]:=0;
			read(x[i],y[i],z[i]);
		end;
	qs(1,m);
//	for i:=1 to m do writeln(x[i],' ',y[i],' ',z[i]);
	for i:=1 to m do
		if getf(x[i])<>getf(y[i]) then
			begin
				//writeln(fa[x[i]],' ',fa[y[i]]);
				//writeln(x[i],' ',y[i]);
				fa[fa[x[i]]]:=fa[y[i]];
				inc(bianshu);
				daoda[bianshu]:=y[i];
				shangyi[bianshu]:=last[x[i]];
				last[x[i]]:=bianshu;
				changdu[bianshu]:=z[i];
		
				inc(bianshu);
				daoda[bianshu]:=x[i];
				shangyi[bianshu]:=last[y[i]];
				last[y[i]]:=bianshu;
				changdu[bianshu]:=z[i];
			end;
	for i:=1 to n do
		fa[i]:=getf(i);
	//for i:=1 to n do writeln(fa[i]);
	read(q);
	for i:=1 to q do
		begin
			read(qx,qy);
			if fa[qx]<>fa[qy]then
				begin
					writeln(-1);
					continue;
				end;
			//flag:=flase;
			zuixiao:=2000000;
			que[1]:=qx;
			lushangzuixiao[qx]:=zuixiao;
			head:=1;
			tail:=1;
			flag:=false;
			while head<=tail do
				begin
					chudui:=que[head];
					tem:=last[chudui];
					while tem<>0 do
						begin
							if jingguo[daoda[tem]]<>i then
								begin
									jingguo[daoda[tem]]:=i;
									tail:=tail+1;
									que[tail]:=daoda[tem];
									lushangzuixiao[daoda[tem]]:=min(lushangzuixiao[chudui],changdu[tem]);
									if que[tail]=qy then
										begin
											flag:=true;
											break;
										end;
								end;
							if flag then break;
							tem:=shangyi[tem];
						end;
					head:=head+1;
				end;
			if jingguo[qy]<>i then writeln(-1)
			else writeln(lushangzuixiao[qy]);
			{flag:=false;
			zuixiao:=2000000;
			dfs(qx,qy,i,zuixiao);
			if flag=false then writeln(-1)
			else writeln(zuixiao);}
		end;
	close(input);
	close(output);
end.