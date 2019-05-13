program translate(input,output);
  const
    maxn=1000;
  var
    n,m,f,r,x,i,ans:longint;
    q,a:array[1..maxn] of longint;

  procedure push(x:longint);
    begin
      if a[x]=1 then exit;
      inc(r);q[r]:=x;a[x]:=1;inc(ans);
      if r-f+1>m then begin
        a[q[f]]:=0;
        inc(f);
      end;
    end;

  begin
    assign(input,'translate.in');reset(input);
    assign(output,'translate.out');rewrite(output);
    fillchar(a,sizeof(a),0);
    readln(m,n);
    ans:=0;
    for i:=1 to n do begin
      read(x);
      push(x);
    end;
    writeln(ans);
    close(input);close(output);
  end.
