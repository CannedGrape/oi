var n,m,q,tot,i,l,r,mid,max,x,y,z:longint;
  a:array[1..100000,1..3]of longint;
  first:array[1..10000]of longint;
  visit:array[1..10000]of boolean;
  procedure build(x,y,z:longint);
    begin
      inc(tot);
      a[tot,1]:=y;
      a[tot,2]:=z;
      a[tot,3]:=first[x];
      first[x]:=tot;
    end;
  function check(x,y,z:longint):boolean;
    var s:longint;
    begin
      s:=first[x]; visit[x]:=true;
      check:=false;
      while s<>0 do
        begin
          if (a[s,2]>=z)and(not visit[a[s,1]]) then
            begin
              visit[a[s,1]]:=true;
              if visit[y] then exit(true);
              check:=check(a[s,1],y,z);
              if check=true then exit;
            end;
          s:=a[s,3];
        end;
      if visit[y] then exit(true);
    end;
  begin
    assign(input,'truck.in');reset(input);
    assign(output,'truck.out');rewrite(output);
    readln(n,m);
    for i:=1 to m do
      begin
        readln(x,y,z);
        build(x,y,z);
        build(y,x,z);
      end;
    readln(q);
    for i:=1 to q do
      begin
        readln(x,y);
        l:=0; r:=100000;
        max:=0;
        while l<=r do
          begin
            mid:=(l+r) div 2;
            fillchar(visit,sizeof(visit),false);
            if check(x,y,mid) then
              begin
                if mid>max then max:=mid;
                l:=mid+1;
              end
            else r:=mid-1;
          end;
        if max<>0 then writeln(max)
        else writeln('-1');
      end;
    close(input);
    close(output);
  end.