program puzzle;
var map:array[-5..35,-5..35]of longint;
      n,m,q,i,j,ex,ey,sx,sy,tx,ty,cnt,ans:longint;
	  used:array[-5..35,-5..35,1..2]of longint;

procedure search(nx,ny,vex,vey,step:longint);
begin
     if (nx=tx) and (ny=ty) and (step<ans) then ans:=step
	 else begin
		        //writeln(nx,' ',ny,' ',vex,' ',vey);
		         if used[vex,vey,1]<>0 then exit;
				 used[vex,vey,1]:=nx;
				 used[vex,vey,2]:=ny;
		         if (map[vex-1,vey]=1) then 
					begin
				         if (nx=(vex-1)) and (ny=vey) then 
							 search(nx+1,ny,vex-1,vey,step+1)
						 else search(nx,ny,vex-1,vey,step+1);
				    end; 
				 if (map[vex+1,vey]=1) then 
					begin
				         if (nx=(vex+1)) and (ny=vey) then 
							 search(nx-1,ny,vex+1,vey,step+1)
						 else search(nx,ny,vex+1,vey,step+1);
				    end; 
				if (map[vex,vey-1]=1) then 
					begin
				         if (nx=vex) and (ny=(vey-1)) then 
							 search(nx,ny+1,vex,vey-1,step+1)
						 else search(nx,ny,vex,vey-1,step+1);
				    end; 
				if (map[vex,vey+1]=1) then 
					begin
				         if (nx=vex) and (ny=(vey+1)) then 
							 search(nx,ny-1,vex,vey+1,step+1)
						 else search(nx,ny,vex,vey+1,step+1);
				    end; 
	 
         end;
end;

begin
     assign(input,'puzzle.in');reset(input);
	 assign(output,'puzzle.out');rewrite(output);
     readln(n,m,q);
	 for i:=-3 to (n+3) do
		 for j:=-3 to (m+3) do
			  map[i,j]:=0;
	 for i:=1 to n do
		 for j:=1 to m do
			 read(map[i,j]);
	   for i:=1 to q do
		   begin
	         ans:=100000000;
	         readln(ex,ey,sx,sy,tx,ty);
			 fillchar(used,sizeof(used),0);
	         search(sx,sy,ex,ey,0);
	         if ans=100000000 then writeln(-1)
				 else 
			 writeln(ans);	 
			end;
     close(input);
	 close(output);
end.
