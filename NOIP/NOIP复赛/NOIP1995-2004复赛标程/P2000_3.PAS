program p2000_3(input,output);{³Ë»ý×î´ó the max multiple}
const maxn=40;maxk=6;
type arr=array[1..50] of integer;
     arr1=array[1..maxn,0..maxk,1..50] of integer;
var f:arr1;
    s:string;
    a:arr;
    n,k,i,j,p,q,k1:integer;
    x,y,temp:arr;

procedure mul(var z:arr;y:arr);
var x:arr;m,n,nx,ny,c:integer;
begin
    for m:=1 to 50 do x[m]:=z[m];
    nx:=50;while (nx>0) and (x[nx]=0) do nx:=nx-1;
    ny:=50;while (ny>0) and (y[ny]=0) do ny:=ny-1;
    fillchar(z,sizeof(z),0);
    c:=0;
    for m:=1 to nx do begin
       for n:=1 to ny do begin
          z[m+n-1]:=z[m+n-1]+c+x[m]*y[n];
          c:=z[m+n-1] div 10;
          z[m+n-1]:=z[m+n-1] mod 10;
       end;
       n:=ny+m;
       while c>0 do begin z[n]:=c mod 10;c:=c div 10;n:=n+1;end;
    end;
end;

procedure max(var x:arr;y:arr);
var nx,ny,i:integer;
begin
     nx:=50;while (nx>0) and (x[nx]=0) do nx:=nx-1;
     ny:=50;while (ny>0) and (y[ny]=0) do ny:=ny-1;
     if nx<ny then for i:=1 to ny do x[i]:=y[i]
     else if ny=nx then begin
          while  (nx>0) and (x[nx]=y[nx])  do nx:=nx-1;
          if (nx>0) and (y[nx]>x[nx]) then for i:=nx downto 1 do x[i]:=y[i];
     end;
end;

begin
     assign(input,'maxmu.in');
     reset(input);
     readln(n,k);readln(s);
     close(input);
     fillchar(a,sizeof(a),0);
     fillchar(f,sizeof(f),0);
     for i:=1 to n do a[i]:=ord(s[i])-ord('0');
     for i:=1 to n do
        for p:=1 to i do f[i,0,p]:=ord(s[i+1-p])-ord('0');
     for i:=2 to n do begin
         if (i-1)>k then k1:=k else k1:=i-1;
         for j:=1 to k1 do begin
             for q:=1 to 50 do temp[q]:=f[i,j,q];
             for p:=j to i-1 do begin
                for q:=1 to 50 do x[q]:=f[p,j-1,q];
                fillchar(y,sizeof(y),0);
                for q:=1 to i-p do y[q]:=a[i+1-q];
                mul(x,y);
                max(temp,x);
              end;
             for q:=1 to 50 do f[i,j,q]:=temp[q];
         end;
      end;
      q:=50;
      while (f[n,k,q]=0) and (q>0) do q:=q-1;
      assign(output,'maxmu.out');
      rewrite(output);
      if q<1 then writeln('Error')
        else
          while q>0 do begin write(f[n,k,q]);q:=q-1;end;
      writeln;
      close(output);
end.


