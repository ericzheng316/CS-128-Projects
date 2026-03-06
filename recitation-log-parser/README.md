<p>
After completing successful internships at <i>Cloudhare</i>, <i>AWS (Atmosphere Warming Services)</i>, and <i>GitBub</i>, you've finally received your first full-time job offer! The prestigious team over at Microshard specifically head-hunted you after hearing tales of your infamous dev-ops skills from their competitors. Microshard is responsible for maintaining services with millions of users worldwide. Downtime in any one of these could lead to tremendous revenue losses. Right on your first day, they've put you in charge of developing in-house tooling to streamline resolution of service outages!
</p>
<p>
As any good developer knows, the first place to look when things go wrong, are the correspondent logs. However, given the sheer volume of diagnostics that some of these systems produce, it would be impossible to manually scour through them for information. 
</p>
<p>
To get around this, you've devised a program that will intelligently parse system logs into easily manipulated data structures, filter for incident periods, report the suspected initial point of failure, and make recommendations based on Microshard's proprietary solutions database. 
</p>

<p>
For this activity, you will implement the following functions: <code class="language-cpp">Parse</code>, <code class="language-cpp">Filter</code>, and <code class="language-cpp">Diagnose</code>.<br>
These functions should be implemented in the file <code class="language-cpp">src/solution.cc</code>.
</p>

<h3>Allowed Headers</h3>

<p>You may only include the following headers in your solution:</p>
<ul>
  <li><code class="language-cpp">"solution.hpp"</code></li>
  <li><code class="language-cpp">"log.hpp"</code></li>
  <li><code class="language-cpp">"helper.hpp"</code></li>
  <li><code class="language-cpp">&lt;fstream&gt;</code></li>
  <li><code class="language-cpp">&lt;string&gt;</code></li>
  <li><code class="language-cpp">&lt;iostream&gt;</code></li>
  <li><code class="language-cpp">&lt;map&gt;</code></li>
  <li><code class="language-cpp">&lt;set&gt;</code></li>
  <li><code class="language-cpp">&lt;stdexcept&gt;</code></li>
</ul>

<h2>Provided Files and Their Purpose</h2>

<p>To complete the task, you will work with the following provided files:</p>

<h4><code class="language-cpp">datetime.hpp</code></h4>
<p>This file defines a <code class="language-cpp">DateTime</code> struct, which represents a timestamp with attributes for the year, month, day, hour, minute, and second. It includes a comparison operator (<code class="language-cpp">&lt;=&gt;</code>, also known as the spaceship operator), allowing easy comparisons between timestamps.</p>

<h4><code class="language-cpp">helper.hpp</code></h4>
<p>Contains the following helper functions: <br/><br/> 
<code class="language-cpp">ParseTimestamp</code>, which takes a string in the format <code class="language-cpp">YYYY-MM-DDTHH:MM:SS</code> (e.g., <code class="language-cpp">2026-03-01T10:14:59</code>) and converts it into a <code class="language-cpp">DateTime</code> object.</p>
<code class="language-cpp">GetRecommendation</code>, which takes a string representing the system component suspected to be the root cause of failure, and returns a string containing recommendations on how to resolve the overarching issue.</p>

<h4><code class="language-cpp">log.hpp</code></h4>
<p>Defines a <code class="language-cpp">Log</code> struct, which represents a log entry with:</p>
<ul>
<li><strong>timestamp</strong>: A string representation of the log time.</li>
<li><strong>component</strong>: A string label for the system component the entry pertains to.</li>
<li><strong>event</strong>: A string representing the event that occurred.</li>
<li><strong>caused_by</strong>: A string representing the system component that caused the <i>event</i> to occur. If no erronous event occured (i.e. SERVICE_UP), this string will be "-".</li>
</ul>
<hr>
<h3>Functions to Implement:</h3>
<div class="box">
<pre><code class="language-cpp">std::vector&lt;Log&gt; Parse(const std::string& input_file);</code></pre>
</div>
<p>
Your implementation of <code class="language-cpp">Parse</code> 
will read a log file that is white space delimited. The first line of the file is a header, and each subsequent line contains four fields: <strong>timestamp</strong>, <strong>component</strong>, <strong>event</strong>, and <strong>caused_by</strong>. Each timestamp (combination of date and time) is unique 
and appears in chronological order.
Below is an example of an input log file:
</p>
<div class="box">
<pre><code class="language-cpp">timestamp           component   event     caused_by
2026-03-01T10:14:58 db-service SERVICE_UP -
2026-03-01T10:14:59 api-gateway SERVICE_UP -
2026-03-01T10:15:01 api-gateway REQUEST_FAILED db-service
2026-03-01T10:15:02 api-gateway RETRY db-service
2026-03-01T10:15:03 db-service CONNECTION_FAIL worker-pool
2026-03-01T10:15:04 db-service TIMEOUT worker-pool
2026-03-01T10:15:05 worker-pool RESOURCE_EXHAUSTED disk-system
2026-03-01T10:15:06 api-gateway SERVICE_DOWN db-service
2026-03-01T10:15:18 api-gateway SERVICE_UP -
</code></pre>
</div>
<p>
Your task is to iterate over each line within the file, creating <code class="language-cpp">Log</code> objects with each relevant field populated, and inserting them into an <code class="language-cpp">std::vector&lt;Log&gt;</code>. Your function will then return the resultant <code class="language-cpp">std::vector&lt;Log&gt;</code> to serve as a representation of the specified log file as a whole. <br/>
If the file cannot be opened, your function should throw an <code class="language-cpp">std::invalid_argument</code> exception.
</p>
<hr>
<div class="box">
<pre><code class="language-cpp">std::vector&lt;Log&gt; Filter(const std::vector&lt;Log&gt;& logs);</code></pre>
</div>
<p>
The Filter function will return a subset of the specified <i>logs</i> vector containing the longest contiguous sequence of erroneous events. To accomplish this, you will iterate over <i>logs</i>, checking each element. If the <code class="language-cpp">Log</code> element at a given index has an event that is <b><i>not</i></b> equal to <code class="language-cpp">"SERVICE_UP"</code>, you will begin tracking a new sequence of erroneous event from that index. This process will be repeated for the entirety of the <i>logs</i> vector. In the case that there is a tie between longest runs, you will select the one that occurred later in the logs. <br/>
If there are no erroneous events in the provided <i>logs</i> vector, return an empty <code class="language-cpp">std::vector&lt;Log&gt;</code>.
</p>
<h3>Example 1.)</h3>
<h5>Given the following <code class="language-cpp">logs</code> vector:</h5>
<ul>
<li>
    <code class="language-cpp">2026-03-01T10:14:58</code>, <code class="language-cpp">db-service</code>
    <code class="language-cpp">SERVICE_UP</code>, <code class="language-cpp">-</code>
</li>
<li>
    <code class="language-cpp">2026-03-01T10:14:59</code>, <code class="language-cpp">api-gateway</code>,
    <code class="language-cpp">REQUEST_FAILED</code>, <code class="language-cpp">db-service</code>
</li>
<li>
    <code class="language-cpp">2026-03-01T10:15:00</code>, <code class="language-cpp">api-gateway</code>,
    <code class="language-cpp">RETRY</code>, <code class="language-cpp">db-service</code>
</li>
<li>
    <code class="language-cpp">2026-03-01T10:15:01</code>, <code class="language-cpp">api-gateway</code>,
    <code class="language-cpp">SERVICE_UP</code>, <code class="language-cpp">-</code>
</li>
    <li>
    <code class="language-cpp">2026-03-01T10:15:02</code>, <code class="language-cpp">db-service</code>,
    <code class="language-cpp">SERVICE_UP</code>, <code class="language-cpp">-</code>
</li>
</ul>

<h5>The resulting <code class="language-cpp">std::vector&lt;Log&gt;</code> should contain:</h5>
<ul>
<li>
    <code class="language-cpp">2026-03-01T10:14:59</code>, <code class="language-cpp">api-gateway</code>,
    <code class="language-cpp">REQUEST_FAILED</code>, <code class="language-cpp">db-service</code>
</li>
<li>
    <code class="language-cpp">2026-03-01T10:15:00</code>, <code class="language-cpp">api-gateway</code>,
    <code class="language-cpp">RETRY</code>, <code class="language-cpp">db-service</code>
</li>
</ul>
<h3>Example 2.)</h3>
<h5>Given the following <code class="language-cpp">logs</code> vector:</h5>
<ul>
<li>
    <code class="language-cpp">2026-03-01T11:00:00</code>, <code class="language-cpp">api-gateway</code>,
    <code class="language-cpp">REQUEST_FAILED</code>, <code class="language-cpp">db-service</code>
</li>
<li>
    <code class="language-cpp">2026-03-01T11:00:01</code>, <code class="language-cpp">api-gateway</code>,
    <code class="language-cpp">RETRY</code>, <code class="language-cpp">db-service</code>
</li>
<li>
    <code class="language-cpp">2026-03-01T11:00:02</code>, <code class="language-cpp">api-gateway</code>,
    <code class="language-cpp">SERVICE_UP</code>, <code class="language-cpp">-</code>
</li>
<li>
    <code class="language-cpp">2026-03-01T11:00:03</code>, <code class="language-cpp">db-service</code>,
    <code class="language-cpp">CONNECTION_FAIL</code>, <code class="language-cpp">worker-pool</code>
</li>
<li>
    <code class="language-cpp">2026-03-01T11:00:04</code>, <code class="language-cpp">db-service</code>,
    <code class="language-cpp">TIMEOUT</code>, <code class="language-cpp">worker-pool</code>
</li>
<li>
    <code class="language-cpp">2026-03-01T11:00:05</code>, <code class="language-cpp">db-service</code>,
    <code class="language-cpp">SERVICE_UP</code>, <code class="language-cpp">-</code>
</li>
</ul>

<h5>The resulting <code class="language-cpp">std::vector&lt;Log&gt;</code> should contain:</h5>
<ul>
<li>
    <code class="language-cpp">2026-03-01T11:00:03</code>, <code class="language-cpp">db-service</code>,
    <code class="language-cpp">CONNECTION_FAIL</code>, <code class="language-cpp">worker-pool</code>
</li>
<li>
    <code class="language-cpp">2026-03-01T11:00:04</code>, <code class="language-cpp">db-service</code>,
    <code class="language-cpp">TIMEOUT</code>, <code class="language-cpp">worker-pool</code>
</li>
</ul>

<hr>

<div class="box">
<pre><code class="language-cpp">std::string Diagnose(const std::vector<Log>& logs);</code></pre>
</div>
<p>
The Diagnose function will produce a string containing the following information: start time and end time of longest erroneous sequence, time elapsed between start and end, suspected root cause of system downtime, and finally, recommended actions to resolve the issue.
</p>
<p>
To find the root cause of the issue, you will analyze the <code class="language-cpp">Log</code> entries within the passed in <i>logs</i> vector. Note that you are guaranteed that this vector only contains <code class="language-cpp">Log</code>s with erroneous events. For the purpose of this activity, we define the root cause to be the <code class="language-cpp">component</code> of the system that has caused at least one erroneous event, and has never sustained an erroneous event due to another <code class="language-cpp">component</code>.
</p>
<p>
Once you have identified this <code class="language-cpp">component</code>, you may pass in the string representing it to the <code class="language-cpp">GetRecommendation</code> function to get the recommended resolution actions.
</p>
<p>The resulting string is expected to be in the following format:</p>
<div class="box">
<pre><code class="language-cpp">start: xxxxx
end: xxxxx
time elapsed: xd, xh, xm, xs
suspected root failure: xxx
recommendation: xxxx
</code></pre>
</div>
<p>Given the example log file shown earlier in the prompt, Diagnose would return the following string:</p>
<div class="box">
<pre><code class="language-cpp">start: 2026-03-01T10:15:01
end: 2026-03-01T10:15:06
time elapsed: 0d, 0h, 0m, 5s
suspected root failure: disk-system
recommendation: check available disk space, I/O utilization, and hardware health.
</code></pre>
</div>
<hr>
<h3>How to compile and run driver.cc</h3>
<p>Before compiling and running driver, make sure to implement <code class="language-cpp">solution.cc</code>.</p>
<p>To compile the program, use:</p>
<pre class="command-line" data-prompt="[coder@localhost] ~ $">
<code class="language-bash">make exec</code></pre>
<p>This will create an executable named <code class="language-cpp">exec</code> in your bin folder.</p>
<p>To run the program, use</p>
<pre class="command-line" data-prompt="[coder@localhost] ~ $">
<code class="language-bash">./bin/exec &lt;input_file&gt;</code></pre>
where &lt;input_file&gt; is the path to the log file to be analyzed.


<h3>How to compile and run tests.cc</h3>
<p>To compile the program, use:</p>
<pre class="command-line" data-prompt="[coder@localhost] ~ $">
<code class="language-bash">make tests</code></pre>
<p>This will create an executable named <code class="language-cpp">tests</code> in your bin folder.</p>
<p>To run the program, use</p>
<pre class="command-line" data-prompt="[coder@localhost] ~ $">
<code class="language-bash">./bin/tests</code></pre>