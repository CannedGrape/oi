var n,i,z,ans,t,l,r:longint;
  check:boolean;
  h:array[1..100000]of longint;
  a,b,max,lazy:array[1..500000]of longint;
  function min(a,b:longint):longint;
    begin
      if a<b then min:=a
      else min:=b;
    end;

  procedure build(tot,x,y:longint);
    var mid:longint;
    begin
      if x=y then
        begin
          a[tot]:=h[x];
          exit;
        end;
      mid:=(x+y) div 2;
      build(tot*2,x,mid);
      build(tot*2+1,mid+1,y);
      a[tot]:=a[tot*2]+a[tot*2+1];
    end;

  procedure find(tot,x,y:longint);
    var mid:longint;
    begin
      if x=y then
        begin
          max[tot]:=a[tot];
          exit;
        end;
      mid:=(x+y) div 2;
      find(tot*2,x,mid);
      find(tot*2+1,mid+1,y);
      max[tot]:=min(max[tot*2],max[tot*2+1]);
    end;

  procedure modify(tot,x,y:longint);
    var mid,l:longint;
    begin
      if ((b[tot]+lazy[tot]*(y-x+1)+y-x+1<=a[tot])or((y=x)and(b[tot]+y-x+1<=a[tot])))and(lazy[tot]+1<=max[tot]) then
        begin
          b[tot]:=y-x+1;
          t:=t+b[tot];
          lazy[tot]:=lazy[tot]+1;
          inc(ans);
          if x=r+1 then
            begin l:=-1; r:=-1; dec(ans); end
          else begin l:=x; r:=y; end;
          exit;
        end;
      if x=y then exit;
      if lazy[tot]>lazy[tot*2] then lazy[tot*2]:=lazy[tot];
      if lazy[tot]>lazy[tot*2+1] then lazy[tot*2+1]:=lazy[tot];
      mid:=(x+y) div 2;
      modify(tot*2,x,mid);
      modify(tot*2+1,mid+1,y);
    end;

  procedure init;
    begin
      readln(n);
      for i:=1 to n do read(h[i]);
      build(1,1,n);
      find(1,1,n);
    end;

  procedure main;
    begin
      l:=-1; r:=-1;
      while t<>a[1] do modify(1,1,n);
      write(ans);
    end;
  begin
    assign(input,'block.in');reset(input);
    assign(output,'block.out');rewrite(output);
    init;
    main;
    close(input);
    close(output);
  end.
