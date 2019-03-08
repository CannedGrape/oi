program Expr;

var a,b:array[0..10010] of longint;
    s:set of char;
    i,j,t,m,k:longint;
    x:char;
    s1:string;
    l:ansistring;

    procedure Double_M;
    begin
      if length(s1)>4 then begin
        s1:=copy(s1,length(s1)-3,4);
        j:=1;
        while s1[j]='0' do inc(j);
        s1:=copy(s1,j,length(s1)-j+1);
      end;
      inc(m);
      val(s1,a[m]);
      s1:='';
    end;

    procedure Avril(y:longint);
    begin
      while y<=b[t] do begin
        case b[t] of
          1:begin
              a[m-1]:=(a[m-1]+a[m]) mod 10000;
              dec(m);
            end;
          2:begin
              a[m-1]:=(a[m-1]*a[m]) mod 10000;
              dec(m);
            end;
        end;
        dec(t);
      end;
      inc(t);b[t]:=k;
    end;

    procedure Angela(y:longint);
    begin
      while y>0 do begin
        case b[y] of
          1:begin
              a[m-1]:=(a[m-1]+a[m]) mod 10000;
              dec(m);
            end;
          2:begin
              a[m-1]:=(a[m-1]*a[m]) mod 10000;
              dec(m);
            end;
        end;
        dec(y);
      end;
    end;

begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);

  s:=['0'..'9'];s1:='';m:=0;b[0]:=0;t:=0;
  readln(l);

  fillchar(a,sizeof(a),0);fillchar(b,sizeof(b),0);
  for i:=1 to length(l) do begin
    if l[i] in s then s1:=s1+l[i];
    if (l[i]='+') or (l[i]='*') then begin
        Double_M;
        case l[i] of
          '+':k:=1;
          '*':k:=2;
        end;
        Avril(k);
      end;
    if i=length(l) then Double_M;
  end;
  Angela(t);

  writeln(a[1]);

  close(input);close(output);
end.
