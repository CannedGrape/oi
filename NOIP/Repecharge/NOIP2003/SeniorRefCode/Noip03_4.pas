program NOIP2003_4_Epidemic;
  const
    maxn=300;maxp=300;
  type
    node=array [0..maxp] of integer;
  var
    i,n,p,min,max,temp,s,smin:integer;
    a:array[1..maxn] of ^node;
    f1,f2:text;fn1,fn2,fileNo:string;
  procedure try(i:integer);
    var
      root1,root2,j,k,m,temp,s0:integer;b:node;flag:boolean;
    begin
      if a[i]^[0]<=1 then begin
        if s<smin then smin:=s;
        exit;
      end;
      s0:=s;
      flag:=true;
      for j:=1 to a[i]^[0] do if (a[a[i]^[j]]^[0]>0) then begin
        flag:=false;
        s:=s0+a[i]^[0]-1;
        if j=1 then root1:=2 else root1:=1;
        root2:=a[i]^[root1];
        temp:=a[root2]^[0];
        for k:=1 to temp do b[k]:=a[root2]^[k];
        for k:=1 to a[i]^[0] do
          if (k<>j) and (k<>root1) then begin
            for m:=1 to a[a[i]^[k]]^[0] do
              a[root2]^[a[root2]^[0]+m]:=a[a[i]^[k]]^[m];
            a[root2]^[0]:=a[root2]^[0]+a[a[i]^[k]]^[0];
          end;
        try(root2);
        a[root2]^[0]:=temp;
        for m:=1 to temp do a[root2]^[m]:=b[m];
      end;
      if flag then begin
        s:=s0+a[i]^[0]-1;
        if s<smin then smin:=s;
        exit;
      end;
    end;
  begin
    write('Input fileNo:');readln(fileNo);
    fn1:='Epidemic.in'+fileNo;fn2:='Epidemic.ou'+fileNo;
    assign(f1,fn1);reset(f1);assign(f2,fn2);rewrite(f2);
    readln(f1,n,p);
    for i:=1 to n do new(a[i]);
    for i:=1 to n do a[i]^[0]:=0;
    for i:=1 to p do begin
      readln(f1,min,max);
      if min>max then begin
        temp:=min;min:=max;max:=temp
      end;
      inc(a[min]^[0]);
      a[min]^[a[min]^[0]]:=max;
    end;
    close(f1);
    s:=1;smin:=300;try(1);
    writeln(f2,smin);close(f2);
  end.