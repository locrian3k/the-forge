// The Forge, Exercise Progress Tracker
// Uses localStorage to persist checkbox state across sessions.

document.addEventListener('DOMContentLoaded', () => {
  const STORAGE_KEY = 'forge-progress';

  // Load saved progress
  function loadProgress() {
    try {
      return JSON.parse(localStorage.getItem(STORAGE_KEY)) || {};
    } catch (e) {
      return {};
    }
  }

  // Save progress
  function saveProgress(progress) {
    localStorage.setItem(STORAGE_KEY, JSON.stringify(progress));
  }

  // Initialize all progress checkboxes
  const progress = loadProgress();
  document.querySelectorAll('.progress-check input[type="checkbox"]').forEach(cb => {
    const id = cb.dataset.exercise;
    if (!id) return;
    cb.checked = !!progress[id];
    cb.addEventListener('change', () => {
      const p = loadProgress();
      p[id] = cb.checked;
      saveProgress(p);
      updateProgressCount();
    });
  });

  // Total exercises across all chapters
  const TOTAL_EXERCISES = 56;

  // Update progress counter if present
  function updateProgressCount() {
    const counter = document.getElementById('progress-count');
    if (!counter) return;
    const p = loadProgress();
    const done = Object.values(p).filter(Boolean).length;
    const pageTotal = document.querySelectorAll('.progress-check input').length;
    counter.textContent = pageTotal > 0 ? `${done}/${TOTAL_EXERCISES}` : `${done}/${TOTAL_EXERCISES}`;

    // Show completion banner if all exercises are done
    checkCompletion(done);
  }

  function checkCompletion(done) {
    const banner = document.getElementById('completion-banner');
    if (!banner) return;
    if (done >= TOTAL_EXERCISES) {
      banner.style.display = 'block';
    } else {
      banner.style.display = 'none';
    }
  }

  updateProgressCount();

  // Highlight active sidebar link
  const currentPage = window.location.pathname.split('/').pop();
  document.querySelectorAll('nav.sidebar a').forEach(link => {
    const href = link.getAttribute('href') || '';
    if (href.endsWith(currentPage)) {
      link.classList.add('active');
    }
  });

  // Preserve sidebar scroll position across page loads
  const sidebar = document.querySelector('nav.sidebar');
  if (sidebar) {
    const savedScroll = sessionStorage.getItem('forge-sidebar-scroll');
    if (savedScroll) {
      sidebar.scrollTop = parseInt(savedScroll, 10);
    }
    sidebar.addEventListener('scroll', () => {
      sessionStorage.setItem('forge-sidebar-scroll', sidebar.scrollTop);
    });
  }
});
