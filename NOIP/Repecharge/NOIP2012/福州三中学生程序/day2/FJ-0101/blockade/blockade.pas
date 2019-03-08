program blockade;
var head,tail,from,too,dist:array[0..200001]of int64;
    pos,flo,path,gone,army,fl,father,cover,tof:array[1..500001]of int64;
    i,j,m,n,k,p,ans:longint;
    l,r,t,q:int64;
procedure inp;
begin
	assign(input,'blockade.in');assign(output,'blockade.out');reset(input);rewrite(output);
end;
procedure outp;
begin
	close(input);close(output);halt;
end;

procedure sort(l,r: longint);
var i,j,x,y: longint;
begin
    i:=l;
    j:=r;
    x:=from[(l+r) div 2];
    repeat
        while from[i]<x do inc(i);
        while x<from[j] do dec(j);
        if not(i>j) then begin
            y:=from[i];
            from[i]:=from[j];
            from[j]:=y;

            y:=too[i];
            too[i]:=too[j];
            too[j]:=y;

            y:=dist[i];
            dist[i]:=dist[j];
            dist[j]:=y;

            inc(i);
            j:=j-1;
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
end;

procedure sort2(l,r:longint);
var i,j,x,y: longint;
begin
    i:=l;
    j:=r;
    x:=fl[army[(l+r) div 2]];
    repeat
        while fl[army[i]]>x do inc(i);
        while x>fl[army[j]] do dec(j);
        if not(i>j) then begin
            y:=army[i];
            army[i]:=army[j];
            army[j]:=y;

            inc(i);
            j:=j-1;
        end;
    until i>j;
    if l<j then sort2(l,j);
    if i<r then sort2(i,r);
end;

procedure init;
begin
     readln(n);
     for i:=1 to n-1 do begin
         readln(from[i],too[i],dist[i]);
         from[i+n-1]:=from[i];
         too[i+n-1]:=too[i];
         dist[i+n-1]:=dist[i];
         q:=q+dist[i];
     end;
     fl[1]:=1;
     sort(1,n-1);
     readln(m);
     for i:=1 to m do read(army[i]);
     k:=2*n-2;

     for i:=1 to k do begin
         if  from[i]<>from[i-1] then begin
             head[from[i]]:=i;
             tail[from[i-1]]:=i-1;
         end;
         if (fl[from[i]]>0)and(fl[too[i]]=0) then begin
            fl[too[i]]:=fl[from[i]]+1;
            father[too[i]]:=from[i];
            tof[too[i]]:=dist[i];
         end;
         if (fl[from[i]]=0)and(fl[too[i]]>0) then begin
            father[from[i]]:=too[i];
            fl[from[i]]:=fl[too[i]]+1;
            tof[from[i]]:=dist[i];
         end;
     end;
     sort2(1,m);
     for i:=1 to n do cover[i]:=1;
     for i:=1 to n do if fl[i]<>1 then cover[father[i]]:=cover[i]+cover[father[i]];
end;

function dfs(now,road:longint):longint;
var i,j,x,y,min:longint;
begin
    min:=maxlongint;
    x:=tof[now];
    if road-x<=0 then exit(now);
    for i:=1 to n do begin
        if (i<>now)and(gone[i]=0)and(fl[i]=2)and(road-x-tof[i]>=0)and(road-x-tof[i]<min) then begin
           min:=road-x-tof[i];
           y:=i;
        end;
    end;
    if (min=maxlongint) then exit(now) else exit(y);
end;

procedure fz(u:longint);
var i:longint;
begin
     for i:=1 to 50000 do gone[i]:=0;
     flo:=fl;
     pos:=army;
     for i:=1 to 50000 do path[i]:=u;
end;

function check(u:int64):boolean;
var i,j,x,y,get:longint;
begin
     get:=1;
     fz(u);
     for i:=1 to m do begin
         inc(gone[pos[i]]);
         while (flo[pos[i]]>2)and(path[i]>=tof[pos[i]]) do
               begin
                  path[i]:=path[i]-tof[pos[i]];
                  pos[i]:=father[pos[i]];
                  inc(gone[pos[i]]);
               end;
     end;
     for i:=1 to m do
         if ((gone[pos[i]]>1)and(flo[pos[i]]=2)) then begin
                dec(gone[pos[i]]);
                pos[i]:=dfs(pos[i],path[i]);
                inc(gone[pos[i]]);
         end;
     for i:=1 to m do
         if gone[pos[i]]>1 then dec(gone[pos[i]]) else get:=get+cover[pos[i]];
     if get=n then exit(true) else exit(false);
end;

begin
	inp;
	init;
        l:=1;
        r:=q;
        while l<>r do begin
              t:=(l+r)div 2;
              if check(t) then begin
                 ans:=t;
                 r:=t;
              end
              else l:=t+1;
        end;
        if (ans<=0)or(ans>q) then ans:=-1;
        writeln(ans);
        outp;
end.
