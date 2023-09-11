<?php
	include("page_header_for_html_tag.html");
?>

<?php
	include("page_header_for_ai4r.html");
?>

<div class="full-window-fixed">
</div>

<div class="max-width-full-heigth-fixed">

	<!--
	<div class="top-bar-container">
		<table class="top-bar-buttons-table">
			<tr>
				<td class="top-bar-motorsoff-button-cell">
					<button
						class="button-push red motorsoff"
						id="buttonMotorsOffForAgent"
						onclick="sendSpeedMessage( 0.0 , 0.0 )"
						>
						STOP MOTORS
						<div class="div-for-button-highlight-on-touchscreen red"></div>
					</button>
				</td>
			</tr>
		</table>
	</div>
	-->


	<div class="main-tabs">
		<input name="tabs" type="radio" id="main-tab-1" checked="checked" class="main-tab-input"/>
		<label for="main-tab-1" class="main-tab-label">Workflow</label>
		<div class="main-tab-panel">
			<?php
				include("ai4r_tab_workflow.html");
			?>
		</div>

		<input name="tabs" type="radio" id="main-tab-2" class="main-tab-input"/>
		<label for="main-tab-2" class="main-tab-label">Compile</label>
		<div class="main-tab-panel">
			<?php
				include("ai4r_tab_compile.html");
			?>
		</div>

		<input name="tabs" type="radio" id="main-tab-3" class="main-tab-input"/>
		<label for="main-tab-3" class="main-tab-label">ROS</label>
		<div class="main-tab-panel">
			<div class="body-container">
				<table class="ros-table">
					<tr>
						<td class="ros-info-cell" style="text-align:right;">
							ROS Domain ID = 
						</td>
						<td class="ros-info-cell">
							<div>
								<pre><span id="rosDomainIdValue"><?php $temp = shell_exec("cat /home/asc-share/default_ros_domain_id"); echo "$temp";?></span></pre>
							</div>
						</td>
					</tr>
					<tr>
						<td class="ros-info-cell" style="text-align:right;">
							Agent Namespace = 
						</td>
						<td class="ros-info-cell">
							<div>
								<pre><span id="agentNamespaceValue"><?php $temp = shell_exec("cat /home/asc-share/default_agent_namespace");echo "/"."$temp";?></span></pre>
							</div>
						</td>
					</tr>
				</table>
			</div>
			<?php
				include("ai4r_tab_ros.html");
			?>
		</div>

		<input name="tabs" type="radio" id="main-tab-4" class="main-tab-input"/>
		<label for="main-tab-4" class="main-tab-label">Info</label>
		<div class="main-tab-panel">
			<?php
				include("ai4r_tab_info.html");
			?>
		</div>
	</div>
</div>


<?php
	include("page_footer.html");
?>
