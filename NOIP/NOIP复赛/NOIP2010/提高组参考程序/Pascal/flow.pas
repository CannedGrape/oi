program flow(input,output);
  const
    maxn=500;
    dx:array[1..4] of longint=(0,0,1,-1);
    dy:array[1..4] of longint=(1,-1,0,0);
  var
    n,m,ans,i,j:longint;
    q:array[1..maxn*maxn*2,1..2] of longint;
    s,h:array[1..maxn,1..maxn] of longint;
    st,ed,dp:array[0..maxn] of longint;
    flag:boolean;

  procedure judge;
    var
      f,r,x,y,tx,ty,k,i:longint;
    begin
      fillchar(s,sizeof(s),0);
      for k:=1 to m do if s[1,k]=0 then begin
        f:=1;r:=0;
        inc(r);q[r,1]:=1;q[r,2]:=k;s[1,k]:=1;
        while f<=r do begin
          x:=q[f,1];y:=q[f,2];inc(f);
          for i:=1 to 4 do begin
            tx:=x+dx[i];ty:=y+dy[i];
            if (tx>=1)and(tx<=n)and(ty>=1)and(ty<=m) then
              if (s[tx,ty]=0)and(h[tx,ty]<h[x,y]) then begin
                inc(r);
                q[r,1]:=tx;q[r,2]:=ty;
                s[tx,ty]:=1;
              end;
          end;
        end;
      end;
      flag:=true;ans:=0;
      for i:=1 to m do
        if s[n,i]=0 then begin
          flag:=false;inc(ans);
        end;
    end;

  procedure work;
    var
      f,r,x,y,tx,ty,k,i,j,min:longint;
    begin
      for k:=1 to m do begin
        f:=1;r:=0;fillchar(s,sizeof(s),0);
        inc(r);q[r,1]:=1;q[r,2]:=k;s[1,k]:=1;
        while f<=r do begin
          x:=q[f,1];y:=q[f,2];inc(f);
          for i:=1 to 4 do begin
            tx:=x+dx[i];ty:=y+dy[i];
            if (tx>=1)and(tx<=n)and(ty>=1)and(ty<=m) then
              if (s[tx,ty]=0)and(h[tx,ty]<h[x,y]) then begin
                inc(r);
                q[r,1]:=tx;q[r,2]:=ty;
                s[tx,ty]:=1;
              end;
          end;
        end;
        for i:=1 to m do
          if s[n,i]<>0 then begin
            st[k]:=i;break;
          end;
        for i:=m downto 1 do
          if s[n,i]<>0 then begin
            ed[k]:=i;break;
          end;
      end;
      fillchar(dp,sizeof(dp),0);
      dp[0]:=0;
      for i:=1 to m do begin
        min:=maxlongint;
        for j:=1 to m do if (st[j]<=i)and(ed[j]>=i) then
          if dp[st[j]-1]<min then min:=dp[st[j]-1];
        dp[i]:=min+1;
      end;
      ans:=dp[m];
    end;

  begin
    assign(input,'flow.in');reset(input);
    assign(output,'flow.out');rewrite(output);
    readln(n,m);
    for i:=1 to n do begin
      for j:=1 to m do
        read(h[i,j]);
      readln;
    end;
    judge;
    if flag then begin
      work;
      writeln(1);
      writeln(ans);
    end
    else begin
      writeln(0);
      writeln(ans);
    end;
    close(input);close(output);
  end.

