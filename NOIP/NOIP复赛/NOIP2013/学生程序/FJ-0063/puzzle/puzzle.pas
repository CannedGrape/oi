type
	v=longint;
const
	inf=387389207;
	fxx:array[1..4]of v=(0,0,1,-1);
	fxy:array[1..4]of v=(1,-1,0,0);
var
	n,m,q,i,j,sx,sy,ex,ey,tx,ty,ans,kongx,kongy,xuanx,xuany,ii,head,tail:v;
	map:array[0..31,0..31]of v;
	que:array[0..162002,1..4]of  v;
	has:array[0..31,0..31,0..31,0..31]of v;
{procedure ff(kongx,kongy,xuanx,xuany:v);
var ii:v;
begin
	writeln(kongx,' ',kongy,' ',xuanx,' ',xuany,' ',has[kongx,kongy,xuanx,xuany]);
	for ii:=1 to 4 do
		if map[kongx+fxx[ii],kongy+fxy[ii]]=1 then
			begin
				if(kongx+fxx[ii]=xuanx)and(kongy+fxy[ii]=xuany)then
					begin
						if has[xuanx,xuany,kongx,kongy]=inf then
							begin
								has[xuanx,xuany,kongx,kongy]:=has[kongx,kongy,xuanx,xuany]+1;
								ff(xuanx,xuany,kongx,kongy);
							end;
					end
				else
					begin
						if has[kongx+fxx[ii],kongy+fxy[ii],xuanx,xuany]=inf then
							begin
								has[kongx+fxx[ii],kongy+fxy[ii],xuanx,xuany]:=has[kongx,kongy,xuanx,xuany]+1;
								ff(kongx+fxx[ii],kongy+fxy[ii],xuanx,xuany);
							end;
					end;
			end;
end;}
begin
	assign(input,'puzzle.in');
	assign(output,'puzzle.out');
	reset(input);
	rewrite(output);
	read(n,m,q);
	for i:=1 to n do
		for j:=1 to m do
			read(map[i,j]);
	//fillchar(has,sizeof(has),23);write(has[0,0,0,0]);
	for i:=1 to q do
		begin
			read(ex,ey,sx,sy,tx,ty);//empty , selected, toward
			if (sx=tx)and(sy=ty)then
				begin
					writeln(0);
					continue;
				end;
			fillchar(has,sizeof(has),23);
			has[ex,ey,sx,sy]:=0;
			
			//ff(ex,ey,sx,sy);
			head:=1;
			tail:=1;
			que[1,1]:=ex;
			que[1,2]:=ey;
			que[1,3]:=sx;
			que[1,4]:=sy;
			//que[1]:=ex*27000+ey*900+sx*30+sy;
			while head<=tail do
				begin
					//tem:=que[head];
					//xuany:=tem mod 30;
					//tem:=tem div 30;
					//xuanx:=tem mod 30;
					//tem:=tem div 30;
					//kongy:=tem mod 30;
					//tem:=tem div 30;
					//kongx:=tem;
					xuany:=que[head,4];
					xuanx:=que[head,3];
					kongy:=que[head,2];
					kongx:=que[head,1];
					//writeln(kongx,' ',kongy,' ',xuanx,' ',xuany,' ',has[kongx,kongy,xuanx,xuany]);
					for ii:=1 to 4 do
						if map[kongx+fxx[ii],kongy+fxy[ii]]=1 then
							begin
								if(kongx+fxx[ii]=xuanx)and(kongy+fxy[ii]=xuany)then
									begin
										if has[xuanx,xuany,kongx,kongy]=inf then
											begin
												has[xuanx,xuany,kongx,kongy]:=has[kongx,kongy,xuanx,xuany]+1;
												//ff(xuanx,xuany,kongx,kongy);
												tail:=tail+1;
												que[tail,1]:=xuanx;
												que[tail,2]:=xuany;
												que[tail,3]:=kongx;
												que[tail,4]:=kongy;
												//que[tail]:=xuanx*27000+xuany*900+kongx*30+kongy;
											end;
									end
								else
									begin
										if has[kongx+fxx[ii],kongy+fxy[ii],xuanx,xuany]=inf then
											begin
												has[kongx+fxx[ii],kongy+fxy[ii],xuanx,xuany]:=has[kongx,kongy,xuanx,xuany]+1;
												//ff(kongx+fxx[ii],kongy+fxy[ii],xuanx,xuany);
												tail:=tail+1;
												que[tail,1]:=kongx+fxx[ii];
												que[tail,2]:=kongy+fxy[ii];
												que[tail,3]:=xuanx;
												que[tail,4]:=xuany;
												//que[tail]:=(kongx+fxx[ii])*27000+(kongy+fxy[ii])*900+xuanx*30+xuany;
										end;
									end;
							end;
					head:=head+1;
					//chudui(head);
					//head:=head+1;
				end;
			ans:=inf;
			for j:=1 to 4 do
				if has[tx+fxx[j],ty+fxy[j],tx,ty]<ans then ans:=has[tx+fxx[j],ty+fxy[j],tx,ty];
			if ans=inf then writeln(-1)
			else writeln(ans)
		end;
	close(input);
	close(output);
end.