program ywt52;
  var head,prev,cost,next,home,aim:array[-10..10000] of longint;
      used:array[-10..10000] of boolean;
      n,e,m,esum,now,ll,rr:longint; ans:int64;
procedure dfs(x,z:longint);
  var i,j:longint;
  begin
    used[x]:=true;
    i:=head[x];
    while i<>0 do
      begin
        if (not(used[next[i]])) and (cost[i]>=z) then dfs(next[i],z);
        i:=prev[i];
      end;
  end;
function check(a,b,limit:longint):boolean;
  begin
    fillchar(used,sizeof(used),false);
    dfs(a,limit);
    if used[b] then exit(true) else exit(false);
  end;
procedure add(a,b,c:longint);
  begin
    inc(esum);
    prev[esum]:=head[a];
    head[a]:=esum;
    next[esum]:=b;
    cost[esum]:=c;
  end;
procedure init;
  var i,j,x,y,z:longint;
  begin
    esum:=0; rr:=0; ll:=maxlongint;
    readln(n,e);
    for i:=1 to e do
      begin
        readln(x,y,z);
        if x=y then continue;
        add(y,x,z);
        add(x,y,z);
        if z>rr then rr:=z;
        if z<ll then ll:=z;
      end;
    readln(m);
    for i:=1 to m do
      readln(home[i],aim[i]);
  end;
procedure main;
  var i,j,l,r:longint;
  begin
    for i:=1 to m do
      begin
        l:=ll; r:=rr; ans:=0;
        if not(check(home[i],aim[i],l)) then
          begin
            writeln(-1);
            continue;
          end;
        while l<=r do
          begin
            if r=l then
              begin
                ans:=l;
                break;
              end;
            if r-l=1 then
              begin
                if check(home[i],aim[i],r) then ans:=r else ans:=l;
                break;
              end;
            now:=(l+r) shr 1;
            if check(home[i],aim[i],now) then l:=now
              else r:=now;
          end;
        writeln(ans);
      end;
  end;
  begin
    assign(input,'truck.in'); reset(input);
    assign(output,'truck.out'); rewrite(output);
    init;
    main;
    close(input);
    close(output);
  end.
